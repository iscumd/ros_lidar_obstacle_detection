//
// Created by aaron on 24/02/18.
//

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

        std::vector<geometry::Point2D> scan_boundary_filter(std::vector<geometry::Point2D> points);
        std::vector<geometry::Obstacle2D> cluster_points(std::vector<geometry::Point2D> points);

        ~lidar_obstacle_detection();
    };
}

#endif //PROJECT_LIDAR_OBSTACLE_DETECTION_H
