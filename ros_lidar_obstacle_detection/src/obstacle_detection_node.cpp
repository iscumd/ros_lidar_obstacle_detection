/**
 *  @Author Team Yeti 2018
 */

#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud.h"
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
std::vector<geometry_msgs::PointStamped> points_stamped;
sensor_msgs::PointCloud cloud;
int start_index;
int end_index;
double filter_x_size;
double filter_y_size;
double filter_origin_x;
double filter_origin_y;
int min_num_clusters;
int max_num_clusters;

tf::StampedTransform transform;

ISC::geometry::Point2D polarToPoint2D(float range, float angle){
    return ISC::geometry::Point2D(range*cos(angle), range*sin(angle));
}

geometry_msgs::Point32 polar_to_cartesian(double theta, double range)
{
    geometry_msgs::Point32 ret;
    ret.x = static_cast<float>(cos(theta) * range);
    ret.y = static_cast<float>(sin(theta) * range);
    return ret;
}

/**
    Called when a new message is published on sensor_msgs/LaserScan
*/
void laserScanCallback_old( const sensor_msgs::LaserScan::ConstPtr& scannedData )
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

void laserScanCallback( const sensor_msgs::LaserScan::ConstPtr& scannedData )
{
    angle_min = scannedData->angle_min;
    angle_max = scannedData->angle_max;
    angle_increment = scannedData->angle_increment;

    range_min = scannedData->range_min;
    range_max = scannedData->range_max;
    ranges = scannedData->ranges;

    timestamp = scannedData->header.stamp;
    cloud.header = scannedData->header;

    if(end_index < 0){
        end_index = int(angle_max / angle_increment);
    }
    cloud.points.clear();
    for(int i = 0; i < ranges.size(); i++){
        if(!std::isinf(ranges.at(i))) {
            auto cartesian_point = polar_to_cartesian(angle_min + i * angle_increment,ranges.at(i));
            cloud.points.push_back(cartesian_point);
        }
    }
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "obstacle_detection");
    ros::NodeHandle n;

    ros::Subscriber laserScanSubscriber = n.subscribe("/scan", 5, laserScanCallback);
    ros::spinOnce();
    ros::Publisher obstaclesPublisher = n.advertise<visualization_msgs::MarkerArray>("obstacle_detection/obstacles", 5);
    ros::Publisher filteredPointsPub = n.advertise<sensor_msgs::PointCloud>("filtered_scan", 5);
    tf::TransformListener listener(ros::Duration(2));
    cloud.header.frame_id = "sick_laser_link";
    cloud.header.stamp = ros::Time::now();
    ros::Time::sleepUntil(ros::Time(ros::Time::now().toSec() + 3));
    ros::spinOnce();
    ros::Rate rate(10.0);
    // n.param("obstacle_min_x_position", minObstacleXPosition, 0);
    n.param("scan_start_index", start_index, 0);
    n.param("scan_end_index", end_index, -1);
    n.param("filter_x_size", filter_x_size, 11.0);
    n.param("filter_y_size", filter_y_size, 4.0);
    n.param("filter_origin_x", filter_origin_x, -2.0);
    n.param("filter_origin_y", filter_origin_y, -2.0);
    n.param("min_num_clusters", min_num_clusters, 1);
    n.param("max_num_clusters", max_num_clusters, 4);

    //make params for filter boundry and min and max clusters

    while(n.ok()){
        rate.sleep();
        sensor_msgs::PointCloud transformed_cloud;
        try{
            const double delay = 0.01;
            listener.waitForTransform("/map","/sick_laser_link", ros::Time(ros::Time::now().toSec() - delay), ros::Duration(2));
            listener.lookupTransform("/map", "/sick_laser_link", ros::Time(ros::Time::now().toSec() - delay), transform);
            listener.transformPointCloud("/map",cloud,transformed_cloud);
        }
        catch (tf::TransformException ex){
//            ROS_ERROR("%s",ex.what());
            ros::spinOnce();
            continue;
        }
        if(transformed_cloud.points.size() < 1){
            ros::spinOnce();
            continue;
        }
    points.clear();
        for(const auto& p: transformed_cloud.points)
        {
            points.push_back(ISC::geometry::Point2D(p.x,p.y));
        }


        std::vector<ISC::geometry::Point2D> filteredPoints;
        filteredPoints = ISC::filtering::filter_by_boundary(ISC::geometry::RectangleBoundary(filter_x_size, filter_y_size, ISC::geometry::Point2D(filter_origin_x, filter_origin_y)), points);
        sensor_msgs::PointCloud filteredPointCloud;
        filteredPointCloud.header = transformed_cloud.header;
        for(const auto& p: filteredPoints)
        {
            geometry_msgs::Point32 gp;
            gp.x = p.get_x();
            gp.y = p.get_y();
            gp.z = transformed_cloud.points.at(0).z;
            filteredPointCloud.points.push_back(gp);
        }
        filteredPointsPub.publish(filteredPointCloud);
        if(filteredPoints.size() < 1)
        {
            continue;
        }
        std::vector<ISC::clustering::cluster> clusters;
//        clusters = ISC::clustering::k_means_cluster(filteredPoints, min_num_clusters, max_num_clusters);
        clusters = ISC::clustering::k_means_cluster(filteredPoints, 2);
        visualization_msgs::MarkerArray msg;
        for(int i = 0; i < clusters.size(); i++){
            if(clusters.at(i).size()<1){ continue;}
            ISC::clustering::cluster * thisCluster = &clusters.at(i);
            visualization_msgs::Marker marker;
            marker.header.stamp = timestamp;
            marker.header.frame_id = "map";
            marker.ns = "obstacle";
            marker.id = i;
            marker.type = marker.CYLINDER;
            marker.color.a = 1;
            marker.color.r = 1;
            marker.color.g = 1;
            marker.color.b = 0;
            marker.action = 0; // 0 add/modify an object, 1 (deprecated), 2 deletes an object, 3 deletes all objects
            geometry_msgs::Point center;
            center.x = (thisCluster->back().get_x() + thisCluster->front().get_x())/ 2;
            center.y = (thisCluster->back().get_y() + thisCluster->front().get_y())/ 2;
            center.z = 0.625;
            geometry_msgs::Pose pose;
            pose.position = center;
            pose.orientation = geometry_msgs::Quaternion();
            marker.pose = pose;
            double size = ISC::geometry::distance(thisCluster->front(), thisCluster->back());
            if(size > 0.25)
            {
                continue;
            }
            geometry_msgs::Vector3 scale;
            scale.x = size;
            scale.y = size;
            scale.z = 1.25;
            marker.scale = scale;
            marker.lifetime = ros::Duration(0.1);
            msg.markers.push_back(marker);
        }
        obstaclesPublisher.publish(msg);
    }
    return 0;
}
