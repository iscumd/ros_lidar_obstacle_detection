//
// Created by aaron on 05/05/18.
//

#include "point2d.h"

#include "catch.hpp"

#include <cfloat>

using ISC::geometry::Point2D;
using ISC::geometry::distance;

TEST_CASE("Point Constructor, regular input", "[constructor][regular_input]"){
    REQUIRE_NOTHROW(Point2D(10,10));
    REQUIRE_NOTHROW(Point2D(0,0));
    REQUIRE_NOTHROW(Point2D(-10,-10));
    REQUIRE_NOTHROW(Point2D(10,-10));
    REQUIRE_NOTHROW(Point2D(-10,10));
}

TEST_CASE("Point Constructor, out of bounds input", "[constructor][out_of_bounds]"){
    REQUIRE_THROWS(Point2D(DBL_MAX, 10));
    REQUIRE_THROWS(Point2D(DBL_MAX, DBL_MAX));
    REQUIRE_THROWS(Point2D(10, DBL_MAX));
    REQUIRE_THROWS(Point2D(-DBL_MAX, 0));
    REQUIRE_THROWS(Point2D(-DBL_MAX, -DBL_MAX));
    REQUIRE_THROWS(Point2D(10, -DBL_MAX));
}

TEST_CASE("Point move test, regular and out of bounds input", "[move][outofbounds][regular]"){
    Point2D point(10,10);

    REQUIRE_THROWS(point.move(DBL_MAX,0));
    REQUIRE_THROWS(point.move(DBL_MAX,DBL_MAX));
    REQUIRE_THROWS(point.move(0,DBL_MAX));
    REQUIRE_THROWS(point.move(-DBL_MAX,0));
    REQUIRE_THROWS(point.move(-DBL_MAX,-DBL_MAX));
    REQUIRE_THROWS(point.move(0,-DBL_MAX));

    REQUIRE_NOTHROW(point.move(0,0));
    REQUIRE_NOTHROW(point.move(-10,-10));
    REQUIRE_NOTHROW(point.move(-10,10));
    REQUIRE_NOTHROW(point.move(10,-10));
    REQUIRE_NOTHROW(point.move(10,-10));
}

TEST_CASE("Point distance test","[distance]"){
    Point2D p1(10,0);
    Point2D p2(0,0);
    REQUIRE(distance(p1,p2) == 10.0);

    p2.move(-10,0);
    REQUIRE(distance(p1,p2) == 20.0);

    p2.move(20,0);
    REQUIRE(distance(p2,p1) == 10.0);

    REQUIRE(distance(p2,p1) == distance(p1,p2));

    p2.move(10,0);
    REQUIRE(distance(p1,p2) == 0.0);
}