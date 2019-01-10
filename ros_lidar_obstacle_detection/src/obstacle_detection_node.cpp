/**
 *  @Author Team Yeti 2018
 */

#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include "sensor_msgs/LaserScan.h"
#include <tf/transform_listener.h>
#include <tf/LinearMath/Matrix3x3.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "boundary.h"
#include "cluster.h"
#include "filter.h"
#include "obstacle.h"
#include "point2d.h"
#include <math.h>
#include <vector>

// LaserScan
float angle_min;        // minimum angle possible
float angle_max;        // maximum angle possible
float angle_increment;  // difference in angle for each reading
float range_min;        // minimum value of ranges
float range_max;        // maximum value of ranges
ros::Time timestamp;
std::vector<float> ranges;
std::vector<ISC::geometry::Point2D> points;

int start_index;
int end_index;
double filter_x_size;
double filter_y_size;
double filter_origin_x;
double filter_origin_y;
int min_num_clusters;
int max_num_clusters;

ISC::geometry::Point2D polarToPoint2D(float range, float angle){
    return ISC::geometry::Point2D(range*cos(angle), range*sin(angle));
}

/**
    Called when a new message is published on sensor_msgs/LaserScan
*/
void laserScanCallback( const sensor_msgs::LaserScan::ConstPtr& scannedData )
{
    angle_min = scannedData->angle_min;
    angle_max = scannedData->angle_max;
    angle_increment = scannedData->angle_increment;

    range_min = scannedData->range_min;
    range_max = scannedData->range_max;
    ranges = scannedData->ranges;

    timestamp = scannedData->header.stamp;

    if(end_index < 0){
        end_index = int(angle_max / angle_increment);
    }

    tf::TransformListener listener;
    tf::StampedTransform transform;
    try{
      listener.lookupTransform("/map", "/sick_laser_link", ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      return;
    }
    tf::Matrix3x3 mat(transform.getRotation());
    double r,p,transformTheta;
    mat.getRPY(r,p,transformTheta);

    for(int i = start_index; i <= end_index; i++){
        points.push_back(polarToPoint2D(ranges.at(i), angle_min + ranges.at(i) * angle_increment));
    }

    for(int i = 0; i < points.size(); i++){
        points.at(i).move(points.at(i).get_x() + transform.getOrigin().x(), points.at(i).get_y() + transform.getOrigin().y());
        points.at(i).move(points.at(i).get_x() * cos(transformTheta) - points.at(i).get_y() * sin(transformTheta), points.at(i).get_y() * cos(transformTheta) + points.at(i).get_x() * sin(transformTheta));
    }
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "obstacle_detection");
    ros::NodeHandle n;

    ros::Subscriber laserScanSubscriber = n.subscribe("scan", 5, laserScanCallback);
    ros::Publisher obstaclesPublisher = n.advertise<visualization_msgs::MarkerArray>("obstacle_detection/obstacles", 5);

    // n.param("obstacle_min_x_position", minObstacleXPosition, 0);
    n.param("scan_start_index", start_index, 0);
    n.param("scan_end_index", end_index, -1);
    n.param("filter_x_size", filter_x_size, 0.0);
    n.param("filter_y_size", filter_y_size, 0.0);
    n.param("filter_origin_x", filter_origin_x, 0.0);
    n.param("filter_origin_y", filter_origin_y, 0.0);
    n.param("min_num_clusters", min_num_clusters, 3);
    n.param("max_num_clusters", max_num_clusters, 7);

    //make params for filter boundry and min and max clusters

    ros::spin();
    while(n.ok()){
        ros::spinOnce();
        if(ranges.size() < 1){
            continue;
        }

        std::vector<ISC::geometry::Point2D> filteredPoints;
        filteredPoints = ISC::filtering::filter_by_boundary(ISC::geometry::RectangleBoundary(filter_x_size, filter_y_size, ISC::geometry::Point2D(filter_origin_x, filter_origin_y)), points);
        
        std::vector<ISC::clustering::cluster> clusters;
        clusters = ISC::clustering::k_means_cluster(filteredPoints, min_num_clusters, max_num_clusters);
        
        visualization_msgs::MarkerArray msg;
        for(int i = 0; i < clusters.size(); i++){
            ISC::clustering::cluster thisCluster = clusters.at(i);
            visualization_msgs::Marker marker;
            marker.header.stamp = timestamp;
            marker.header.frame_id = "map";
            marker.ns = "obstacle";
            marker.id = i;
            marker.type = marker.CYLINDER;
            marker.action = 0; // 0 add/modify an object, 1 (deprecated), 2 deletes an object, 3 deletes all objects
            geometry_msgs::Point center;
            center.x = std::sqrt(std::pow(thisCluster.back().get_x() - thisCluster.front().get_x(), 2));
            center.y = std::sqrt(std::pow(thisCluster.back().get_y() - thisCluster.front().get_y(), 2));
            center.z = 0.0;
            geometry_msgs::Pose pose;
            pose.position = center;
            pose.orientation = geometry_msgs::Quaternion();
            marker.pose = pose;
            double size = ISC::geometry::distance(thisCluster.front(), thisCluster.back());
            geometry_msgs::Vector3 scale;
            scale.x = size;
            scale.y = size;
            scale.z = 1.25;
            marker.scale = scale;
            marker.lifetime = ros::Duration(0);
            msg.markers.push_back(marker);
        }
        obstaclesPublisher.publish(msg);
    }
    return 0;
}
