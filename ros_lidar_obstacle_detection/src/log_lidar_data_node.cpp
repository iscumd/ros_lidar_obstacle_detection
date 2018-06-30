/**
 *  @Author Team Yeti 2018
 */

//#include "obstacle.h"

#include "geometry_msgs/Point.h"
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

#include <vector>

// LaserScan
float angle_min;        // minimum angle possible
float angle_max;        // maximum angle possible
float angle_increment;  // difference in angle for each reading
float range_min;        // minimum value of ranges
float range_max;        // maximum value of ranges
float* ranges;          // Dont do this, use std::array

int start_index;
int end_index;

/**
    Called when a new message is published on sensor_msgs/LaserScan
*/
void laserScanCallback( const sensor_msgs::LaserScan::ConstPtr& scannedData )
{
    //    angle_min = scannedData->angle_min;
    //    angle_max = scannedData->angle_max;
    //    angle_increment = scannedData->angle_increment;
    //
    //    range_min = scannedData->range_min;
    //    range_max = scannedData->range_max;
    //    ranges = scannedData->ranges;
}

int main( int argc, char** argv )
{
    ros::init( argc, argv, "obstacle_detection" );
    ros::NodeHandle n;

    ros::Subscriber laserScanSubscriber
        = n.subscribe( "sensor_msgs/LaserScan", 5, laserScanCallback );

    ros::spin();
    return 0;
}
