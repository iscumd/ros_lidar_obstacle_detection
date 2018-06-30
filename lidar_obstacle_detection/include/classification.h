//
// Created by aaron on 30/06/18.
//

#ifndef LIDAR_OBSTACLE_DETECTION_CLASSIFICATION_H
#define LIDAR_OBSTACLE_DETECTION_CLASSIFICATION_H

#include "cluster.h"

using ISC::clustering::cluster;
using ISC::geometry::Point2D;
using ISC::geometry::Obstacle2D;
using ISC::geometry::ObstacleType;

namespace ISC
{
namespace classification
{
    double avg_slope( const cluster& clust );
    double sum_squared_slope_deviation( const cluster& clust );
    Obstacle2D classify_obstacle( const cluster& clus );
}
}

#endif  // LIDAR_OBSTACLE_DETECTION_CLASSIFICATION_H
