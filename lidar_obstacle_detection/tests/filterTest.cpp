//
// Created by aaron on 08/06/18.
//

#include "filter.h"

#include "catch.hpp"

using ISC::geometry::Point2D;
using ISC::filtering::filter_by_boundary;
using ISC::geometry::RectangleBoundary;

TEST_CASE( "Rectangle Boundary filter", "[Boundary][filter]" )
{
    std::vector<Point2D> points
            = { { -1, -1 }, { 1, 1 },     { -10, -11 }, { 1, 0 },   { 0, 1 },    { 20, 20 },
                { -1, 0 },  { -13, -10 }, { 0, -1 },    { 21, 20 }, { -13, -13 }, {-22,0} };

    RectangleBoundary boundary(30,30,{-15,-15});

    auto filtered_points = filter_by_boundary(boundary, points);
    
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-1,-1)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(1,1)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-10,-11)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(1,0)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(0,1)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-1,0)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-13,-10)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(0,-1)) != filtered_points.end());
    REQUIRE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-13,-13)) != filtered_points.end());

    REQUIRE_FALSE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(20,20)) != filtered_points.end());
    REQUIRE_FALSE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(21,20)) != filtered_points.end());
    REQUIRE_FALSE(std::find(filtered_points.begin(), filtered_points.end(), Point2D(-22,0)) != filtered_points.end());
}