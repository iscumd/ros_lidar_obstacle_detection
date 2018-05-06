/**
 * @author Aaron F Cofield
 * @date 5/5/2018
 * @brief k means clustering header
 */

#ifndef LIDAR_OBSTACLE_DETECTION_CLUSTER_H
#define LIDAR_OBSTACLE_DETECTION_CLUSTER_H

#include "obstacle.h"
#include "point2d.h"

#include <stdlib.h>
#include <time.h>
#include <vector>

/*
 * This file contains helper functions that implement k-means clustering
 *  Target API:
 *      Input->std::vector<Point2D>
 *      output->std::vector<geometry::Obstacle>
 */

namespace ISC
{
namespace cluster
{

    using geometry::Obstacle2D;
    using geometry::Point2D;
    using geometry::ObstacleType;

    /**
     * @brief Cluster points using kmeans clustering
     *
     *  This function implements the well defined kmeans clustering algorithm. Given a
     * vector of unannotated points
     *  it will group them in a way that combines points that are related to each other.
     *
     *  The k value is automatically determined by using the Elbow method. The elbow
     * method plots the K values against
     *  the sum of squared errors. The elbow point or optimal k value is the maximum of
     * the second derivative of the plot.
     *
     *  For reliable elbow point detection, max - min must be greater than 4.
     *
     *  The algorithm is implemented according to this resource
     * https://mubaris.com/2017/10/01/kmeans-clustering-in-python/
     *
     * @param points points to be clustered
     * @param max_num_clusters the maximum number of clusters there could possibly be in
     * the point group.
     * @param min_num_clusters the minimum number of clusters there could possible be in
     * the point group.
     * @return obstacle objects representing the clustered points
     */
    std::vector<obstacle> k_means_cluster( const std::vector<Point2D>& points,
                                           const int& max_num_clusters,
                                           const int& min_num_clusters );

    /**
     * @brief Cluster points using kmeans clustering
     *
     *  This function implements the well defined kmeans clustering algorithm. Given a
     * vector of unannotated points
     *  it will group them in a way that combines points that are related to each other.
     *
     *  The algorithm is implemented according to this resource
     * https://mubaris.com/2017/10/01/kmeans-clustering-in-python/
     *
     * @param points points to be clustered
     * @param num_clusters the number of clusters that should be in the point group. k
     * value
     * @return obstacle objects representing the clustered points
     */
    std::vector<obstacle> k_means_cluster( const std::vecotr<Point2D>& points,
                                           const unsigned int& num_clusters );

} /* cluster*/
}  // ISC

#endif  // LIDAR_OBSTACLE_DETECTION_CLUSTER_H
