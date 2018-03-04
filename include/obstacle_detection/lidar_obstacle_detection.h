/**
    @author Team Yeti 2019
    @date 2/26/2018
*/
#ifndef PROJECT_LIDAR_OBSTACLE_DETECTION_H
#define PROJECT_LIDAR_OBSTACLE_DETECTION_H

#include "point.h"
#include "obstacle.h"
#include "boundary.h"

//TODO: implement functions using Tf

namespace ISC {
    class lidar_obstacle_detection {
    public:

        lidar_obstacle_detection();

        // assuming there is some sort of vector of points? just putting this here for now
        std::vector<geometry::Point2D> lidarPoints;

        std::vector<geometry::Point2D> scan_boundary_filter(std::vector<geometry::Point2D> points);
        std::vector<geometry::Obstacle2D> cluster_points(std::vector<geometry::Point2D> points);

        /** TODO: document things
        */
        std::vector<geometry::Point2D> filter_by_boundary(const RectangleBoundary& bound) const;

        ~lidar_obstacle_detection();
    };
}

#endif //PROJECT_LIDAR_OBSTACLE_DETECTION_H
