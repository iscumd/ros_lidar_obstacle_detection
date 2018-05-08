//
// Created by aaron on 06/05/18.
//

#include "cluster.h"

#include "catch.hpp"

using ISC::geometry::Point2D;
using ISC::clustering::k_means_cluster;
//
// TEST_CASE( "Point Cluster Test, k = 2", "[cluster][k=2]" )
//{
//    const int K = 2;
//    std::vector<Point2D> points = {
//            {-1,-1},
//            {1,1},
//            {1,0},
//            {0,1},
//            {20,20},
//            {-1,0},
//            {0,-1}
//    };
//
//    auto clusters = k_means_cluster(points, K);
//
//    REQUIRE((clusters.at(0).size() == 1 || clusters.at(1).size() == 1));
//    REQUIRE((clusters.at(0).size() == 6 || clusters.at(1).size() == 6));
//
//    points.emplace_back(Point2D(21,20));
//    clusters = k_means_cluster(points, K);
//    REQUIRE((clusters.at(0).size() == 2 || clusters.at(1).size() == 2));
//    REQUIRE((clusters.at(0).size() == 6 || clusters.at(1).size() == 6));
//
//}

TEST_CASE( "Point Cluster Test, k = 3", "[cluster][k=2]" )
{
    const int K = 3;
    std::vector<Point2D> points
        = { { -1, -1 }, { 1, 1 },     { -10, -11 }, { 1, 0 },   { 0, 1 },    { 20, 20 },
            { -1, 0 },  { -13, -10 }, { 0, -1 },    { 21, 20 }, { -13, -13 } };

    auto clusters = k_means_cluster( points, K );

    REQUIRE( ( clusters.at( 0 ).size() == 2 || clusters.at( 1 ).size() == 2
               || clusters.at( 2 ).size() == 2 ) );
    REQUIRE( ( clusters.at( 0 ).size() == 3 || clusters.at( 1 ).size() == 3
               || clusters.at( 2 ).size() == 3 ) );
    REQUIRE( ( clusters.at( 0 ).size() == 6 || clusters.at( 1 ).size() == 6
               || clusters.at( 2 ).size() == 6 ) );
}