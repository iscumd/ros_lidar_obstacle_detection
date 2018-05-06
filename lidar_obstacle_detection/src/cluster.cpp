//
// Created by aaron on 05/05/18.
//

#include "cluster.h"

#define MAX_RAND_NUM 50

namespace ISC
{
namespace cluster
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
            for ( size_t i = 1; i < points.size(); ++i )
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
    }//namespace

    std::vector<Obstacle2D> k_means_cluster( const std::vector<Point2D>& points,
                                             const int& max_num_clusters,
                                             const int& min_num_clusters )
    {
    }

    std::vector<Obstacle2D> k_means_cluster( const std::vector<Point2D>& points,
                                             const unsigned int& num_clusters )
    {
        std::vector<Point2D> random_points;
        random_points.reserve( num_clusters );

        srand( time( nullptr ) );

        for ( auto& random_point : random_points )
        {
            random_point = { rand() % MAX_RAND_NUM, rand() % MAX_RAND_NUM };
        }
    }


}  // namespace cluster
}  // namespace ISC