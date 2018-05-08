//
// Created by aaron on 05/05/18.
//

#include "cluster.h"


namespace ISC {
    namespace clustering {

        namespace {
            unsigned int get_index_of_closest_point(const std::vector<Point2D> &points,
                                                    const Point2D &point) {
                if (points.size() < 0) {
                    return 0;
                }
                double min_dist = ISC::geometry::distance(point, points.at(0));
                unsigned int min_dist_index = 0;
                for (unsigned int i = 1; i < points.size(); ++i) {
                    double dist = ISC::geometry::distance(point, points.at(i));
                    if (dist < min_dist) {
                        min_dist = dist;
                        min_dist_index = i;
                    }
                }

                return min_dist_index;
            }

            Point2D get_avg_cluster_point(const cluster &points) {
                if (points.size() < 1) {
                    throw std::runtime_error("Cannot find average of empty vector!");
                }

                double x_sum = 0;
                double y_sum = 0;

                for (const auto &point : points) {
                    x_sum += point.get_x();
                    y_sum += point.get_y();
                }

                return {x_sum / points.size(), y_sum / points.size()};
            }

        }  // namespace

        std::vector<cluster> k_means_cluster(const std::vector<Point2D> &points,
                                             const unsigned int &max_num_clusters,
                                             const unsigned int &min_num_clusters) {
            // TODO: airfield20 implement elbow point detection
            std::vector<std::vector<cluster>> cluster_groups;
            for (unsigned int i = min_num_clusters; i <= max_num_clusters; ++i) {
                cluster_groups.emplace_back(k_means_cluster(points, i));
            }

            // construct line from (max,sse(max)) (min,sse(min))
            double avg_min_sse = 0;
            for (const auto &clus : cluster_groups.at(0)) {
                avg_min_sse += sum_of_squared_errors(clus);
            }
            avg_min_sse = avg_min_sse / cluster_groups.at(0).size();
            double avg_max_sse = 0;
            for (const auto &clus : cluster_groups.back()) {
                avg_max_sse += sum_of_squared_errors(clus);
            }
            avg_max_sse = avg_max_sse / cluster_groups.at(0).size();

            Eigen::Vector3d min(min_num_clusters, avg_min_sse, 0.0);
            Eigen::Vector3d max(min_num_clusters, avg_max_sse, 0.0);

            Eigen::ParametrizedLine<double, 3> line = line.Through(min, max);

            double max_dist = 0;
            int elbow_point = -1;
            for(unsigned int k = min_num_clusters; k <= max_num_clusters; ++k)
            {
                double avg_sse = 0;
                for (const auto &clus : cluster_groups.at(k - min_num_clusters)) {
                    avg_sse += sum_of_squared_errors(clus);
                }
                avg_sse = avg_sse / cluster_groups.at(k - min_num_clusters).size();
                Eigen::Vector3d curr_offset (k, avg_sse);
                double dist = line.distance(curr_offset);
                if(std::abs(dist) > max_dist)
                {
                    max_dist = dist;
                    elbow_point = k;
                }
            }

            return cluster_groups.at(elbow_point - min_num_clusters);

        }

        std::vector<cluster> k_means_cluster(const std::vector<Point2D> &points,
                                             const unsigned int &num_clusters) {
            if (num_clusters < 1) {
                throw std::runtime_error("num_clusters must be positive");
            }
            if (points.size() < 1) {
                throw std::runtime_error("cannot cluster empty point vector");
            }

            std::vector<Point2D> avg_points, prev_avg_points;
            avg_points.resize(num_clusters);
            prev_avg_points.resize(num_clusters);

            srand(time(nullptr));

            for (unsigned int i = 0; i < num_clusters; ++i) {
                avg_points.at(i)
                        = (Point2D(rand() % MAX_RAND_NUM, rand() % MAX_RAND_NUM));
                prev_avg_points.at(i) = Point2D(0, 0);
            }

            std::vector<cluster> clusters;

            while (avg_points != prev_avg_points) {
                clusters.clear();
                clusters.resize(num_clusters);
                for (const auto &point : points) {
                    unsigned int index = get_index_of_closest_point(avg_points, point);
                    clusters.at(index).push_back(point);
                }

                prev_avg_points = avg_points;

                for (unsigned int i = 0; i < clusters.size(); ++i) {
                    if (clusters.at(i).size() > 0) {
                        avg_points.at(i) = get_avg_cluster_point(clusters.at(i));
                    } else {
                        avg_points.at(i)
                                = (Point2D(rand() % MAX_RAND_NUM, rand() % MAX_RAND_NUM));
                    }
                }
            }

            return clusters;
        }

        double sum_of_squared_errors(const cluster &points) {

            if (points.size() < 2) {
                throw std::runtime_error(
                        "Cannot calculate the SSE of a cluster of less than 2 points");
            }

            double mean = 0;
            std::vector<double> distances;

            for (unsigned int i = 0; i < points.size(); ++i) {
                for (unsigned int j = i + 1; j < points.size(); ++j) {
                    double dist = ISC::geometry::distance(points.at(i), points.at(j));
                    mean += dist;
                    distances.push_back(dist);
                }
            }

            mean = mean / points.size();

            double sum = 0;

            for (const auto &distance : distances) {
                sum += std::pow(distance - mean, 2);
            }

            return sum;
        }

    }  // namespace clustering
}  // namespace ISC