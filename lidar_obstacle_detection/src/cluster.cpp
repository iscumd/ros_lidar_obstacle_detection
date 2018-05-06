//
// Created by aaron on 05/05/18.
//

#include "cluster.h"

#include <stdexcept>

#define MAX_RAND_NUM 50

namespace ISC
{
namespace clustering
{

    namespace
    {
        unsigned int get_index_of_closest_point( const std::vector<Point2D>& points,
                                                 const Point2D& point )
        {
            if ( points.size() < 0 )
            {
                return 0;
            }
            double min_dist = ISC::geometry::distance( point, points.at( 0 ) );
            unsigned int min_dist_index = 0;
            for ( unsigned int i = 1; i < points.size(); ++i )
            {
                double dist = ISC::geometry::distance( point, points.at( i ) );
                if ( dist < min_dist )
                {
                    min_dist       = dist;
                    min_dist_index = i;
                }
            }

            return min_dist_index;
        }

        Point2D get_avg_cluster_point( const cluster& points )
        {
            if ( points.size() < 1 )
            {
                throw std::runtime_error( "Cannot find average of empty vector!" );
            }

            double x_sum = 0;
            double y_sum = 0;

            for ( const auto& point : points )
            {
                x_sum += point.get_x();
                y_sum += point.get_y();
            }

            return { x_sum / points.size(), y_sum / points.size() };
        }

    }  // namespace

    std::vector<cluster> k_means_cluster( const std::vector<Point2D>& points,
                                          const int& max_num_clusters,
                                          const int& min_num_clusters )
    {
    }

    std::vector<cluster> k_means_cluster( const std::vector<Point2D>& points,
                                          const unsigned int& num_clusters )
    {
        if ( num_clusters < 1 )
        {
            throw std::runtime_error( "num_clusters must be positive" );
        }
        if ( points.size() < 1 )
        {
            throw std::runtime_error( "cannot cluster empty point vector" );
        }

        std::vector<Point2D> avg_points, prev_avg_points;
        avg_points.resize( num_clusters );
        prev_avg_points.resize( num_clusters );

        srand( time( nullptr ) );

        for ( unsigned int i = 0; i < num_clusters; ++i )
        {
            avg_points.at( i )
                = ( Point2D( rand() % MAX_RAND_NUM, rand() % MAX_RAND_NUM ) );
            prev_avg_points.at( i ) = Point2D( 0, 0 );
        }

        std::vector<cluster> clusters;

        while ( avg_points != prev_avg_points )
        {
            clusters.clear();
            clusters.resize( num_clusters );
            for ( const auto& point : points )
            {
                unsigned int index = get_index_of_closest_point( avg_points, point );
                clusters.at( index ).push_back( point );
            }

            prev_avg_points = avg_points;

            for ( unsigned int i = 0; i < clusters.size(); ++i )
            {
                if ( clusters.at( i ).size() > 0 )
                {
                    avg_points.at( i ) = get_avg_cluster_point( clusters.at( i ) );
                }
                else
                {
                    avg_points.at( i )
                        = ( Point2D( rand() % MAX_RAND_NUM, rand() % MAX_RAND_NUM ) );
                }
            }
        }

        return clusters;
    }


}  // namespace clustering
}  // namespace ISC