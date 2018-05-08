/**
 * @author Aaron F Cofield
 * @date 5/5/2018
 * @brief k means clustering header
 */

#ifndef LIDAR_OBSTACLE_DETECTION_CLUSTER_H
#define LIDAR_OBSTACLE_DETECTION_CLUSTER_H

#include "obstacle.h"
#include "point2d.h"

#include "Eigen/Core"
#include "Eigen/Geometry"
#include "Eigen/src/Geometry/ParametrizedLine.h"

#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <vector>

// TODO: airfield20, this should be user defined. Results will be successful more often
// with a more accurate range
#ifndef MAX_RAND_NUM
#define MAX_RAND_NUM 50
#endif


/*
 * This file contains helper functions that implement k-means clustering
 *  Target API:
 *      Input->std::vector<Point2D>
 *      output->std::vector<geometry::Obstacle>
 */

namespace ISC
{
namespace clustering
{

    using geometry::Obstacle2D;
    using geometry::Point2D;
    using geometry::ObstacleType;

    typedef std::vector<Point2D> cluster;

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
    std::vector<cluster> k_means_cluster( const std::vector<Point2D>& points,
                                          const unsigned int& max_num_clusters,
                                          const unsigned int& min_num_clusters );

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
    std::vector<cluster> k_means_cluster( const std::vector<Point2D>& points,
                                          const unsigned int& num_clusters );

    /**
     * @brief calculates the sum of squared errors of the distance between a cluster's
     * points
     *
     * The SSE is calculated by subtracting the mean distance between points from each
     * distance,
     * then calculating the sum
     * @param points cluster for which the SSE will be calculated
     * @return the sum of squared errors of the distance between the cluster's points
     */
    double sum_of_squared_errors( const cluster& points );


}  // namespace clustering
}  // namespace ISC

#endif  // LIDAR_OBSTACLE_DETECTION_CLUSTER_H
