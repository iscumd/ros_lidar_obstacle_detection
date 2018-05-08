//
// Created by aaron on 06/05/18.
//

#include "cluster.h"

#include "catch.hpp"

using ISC::geometry::Point2D;
using ISC::geometry::distance;
using ISC::clustering::k_means_cluster;
using ISC::clustering::sum_of_squared_errors;


TEST_CASE( "Sum of squared Errors Test, computer calculated", "[SSE][computer]" )
{
    std::vector<Point2D> points
        = { { 0, 10 }, { 1, 5 }, { 6, 7 }, { 0, 0 }, { -3, -10 } };
    std::vector<double> distances;

    distances.emplace_back( distance( points.at( 0 ), points.at( 1 ) ) );
    distances.emplace_back( distance( points.at( 0 ), points.at( 2 ) ) );
    distances.emplace_back( distance( points.at( 0 ), points.at( 3 ) ) );
    distances.emplace_back( distance( points.at( 0 ), points.at( 4 ) ) );
    distances.emplace_back( distance( points.at( 1 ), points.at( 2 ) ) );
    distances.emplace_back( distance( points.at( 1 ), points.at( 3 ) ) );
    distances.emplace_back( distance( points.at( 1 ), points.at( 4 ) ) );
    distances.emplace_back( distance( points.at( 2 ), points.at( 3 ) ) );
    distances.emplace_back( distance( points.at( 2 ), points.at( 4 ) ) );
    distances.emplace_back( distance( points.at( 3 ), points.at( 4 ) ) );

    double mean = 0;
    for ( const auto& dist : distances )
    {
        mean += dist;
    }
    mean = mean / 5;

    std::vector<double> deviations_squared;
    for ( const auto& dist : distances )
    {
        deviations_squared.emplace_back( std::pow( dist - mean, 2 ) );
    }
    double sum = 0;
    for ( const auto& dev : deviations_squared )
    {
        sum += dev;
    }

    REQUIRE( sum == sum_of_squared_errors( points ) );
}


TEST_CASE( "Point Cluster Test, k = 2", "[cluster][k=2]" )
{
    const int K = 2;
    std::vector<Point2D> points
        = { { -1, -1 }, { 1, 1 }, { 1, 0 }, { 0, 1 }, { 20, 20 }, { -1, 0 }, { 0, -1 } };

    auto clusters = k_means_cluster( points, K );

    REQUIRE( ( clusters.at( 0 ).size() == 1 || clusters.at( 1 ).size() == 1 ) );
    REQUIRE( ( clusters.at( 0 ).size() == 6 || clusters.at( 1 ).size() == 6 ) );

    points.emplace_back( Point2D( 21, 20 ) );
    clusters = k_means_cluster( points, K );
    REQUIRE( ( clusters.at( 0 ).size() == 2 || clusters.at( 1 ).size() == 2 ) );
    REQUIRE( ( clusters.at( 0 ).size() == 6 || clusters.at( 1 ).size() == 6 ) );
}

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