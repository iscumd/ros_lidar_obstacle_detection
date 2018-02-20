#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "geometry_msgs/Point.h"
#include "obstacletype.h"

class Obstacle {
    geometry_msgs::Point position;
    ObstacleType obsType;
};

#endif
