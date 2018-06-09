//
// Created by aaron on 08/06/18.
//

#ifndef LIDAR_OBSTACLE_DETECTION_FILTER_H
#define LIDAR_OBSTACLE_DETECTION_FILTER_H

#include "boundary.h"
#include "point2d.h"

#include <vector>

namespace ISC
{
namespace filtering
{
    /**
     * @brief filter 2d points based on a rectangular boundary
     * Boundary filter is NOT inclusive, i.e. points that lie on the boundary will not be included in the return
     * @param bound boundary to filter points against
     * @param points points to be filtered
     * @return a vector of points that lie inside the boundary
     */
    std::vector<geometry::Point2D>
    filter_by_boundary( const ISC::geometry::RectangleBoundary& bound,
                        const std::vector<ISC::geometry::Point2D>& points );
}
}


#endif  // LIDAR_OBSTACLE_DETECTION_FILTER_H
