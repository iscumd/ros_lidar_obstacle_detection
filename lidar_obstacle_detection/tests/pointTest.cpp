//
// Created by aaron on 05/05/18.
//

#include "point2d.h"

#include "catch.hpp"

#include <cfloat>

using ISC::geometry::Point2D;

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