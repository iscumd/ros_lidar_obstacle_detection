//
// Created by aaron on 05/05/18.
//

#include "cluster.h"

namespace ISC{ namespace cluster {

        std::vector<obstacle> k_means_cluster( const std::vector<Point2D> & points, const int & max_num_clusters, const int & min_num_clusters ) {

        }

        std::vector<obstacle> k_means_cluster( const std::vecotr<Point2D> & points, const unsigned int & num_clusters ) {
            std::vector<Point2D> random_points;
            random_points.reserve(num_clusters);

            srand(time(NULL));

            for(size_t i = 0; i < random_points.size(); i++ ){
                random_points.emplace_back( { rand() % 50, rand() % 50 } );
            }



        }


} /*cluster*/} //ISC