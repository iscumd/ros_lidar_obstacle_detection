//
// Created by aaron on 05/05/18.
//

#include "boundary.h"
#include "point2d.h"

#include "catch.hpp"

#include <algorithm>
#include <cfloat>

using ISC::geometry::Point2D;
using ISC::geometry::RectangleBoundary;
using ISC::geometry::distance;
using ISC::geometry::isInside;

TEST_CASE( "Point Constructor, regular input", "[constructor][regular_input]" )
{
    REQUIRE_NOTHROW( Point2D( 10, 10 ) );
    REQUIRE_NOTHROW( Point2D( 0, 0 ) );
    REQUIRE_NOTHROW( Point2D( -10, -10 ) );
    REQUIRE_NOTHROW( Point2D( 10, -10 ) );
    REQUIRE_NOTHROW( Point2D( -10, 10 ) );
}

TEST_CASE( "Point Constructor, out of bounds input", "[constructor][out_of_bounds]" )
{
    REQUIRE_THROWS( Point2D( DBL_MAX, 10 ) );
    REQUIRE_THROWS( Point2D( DBL_MAX, DBL_MAX ) );
    REQUIRE_THROWS( Point2D( 10, DBL_MAX ) );
    REQUIRE_THROWS( Point2D( -DBL_MAX, 0 ) );
    REQUIRE_THROWS( Point2D( -DBL_MAX, -DBL_MAX ) );
    REQUIRE_THROWS( Point2D( 10, -DBL_MAX ) );
}

TEST_CASE( "Point move test, regular and out of bounds input",
           "[move][outofbounds][regular]" )
{
    Point2D point( 10, 10 );

    REQUIRE_THROWS( point.move( DBL_MAX, 0 ) );
    REQUIRE_THROWS( point.move( DBL_MAX, DBL_MAX ) );
    REQUIRE_THROWS( point.move( 0, DBL_MAX ) );
    REQUIRE_THROWS( point.move( -DBL_MAX, 0 ) );
    REQUIRE_THROWS( point.move( -DBL_MAX, -DBL_MAX ) );
    REQUIRE_THROWS( point.move( 0, -DBL_MAX ) );

    REQUIRE_NOTHROW( point.move( 0, 0 ) );
    REQUIRE_NOTHROW( point.move( -10, -10 ) );
    REQUIRE_NOTHROW( point.move( -10, 10 ) );
    REQUIRE_NOTHROW( point.move( 10, -10 ) );
    REQUIRE_NOTHROW( point.move( 10, -10 ) );
}

TEST_CASE( "Point distance test", "[distance]" )
{
    Point2D p1( 10, 0 );
    Point2D p2( 0, 0 );
    REQUIRE( distance( p1, p2 ) == 10.0 );

    p2.move( -10, 0 );
    REQUIRE( distance( p1, p2 ) == 20.0 );

    p2.move( 20, 0 );
    REQUIRE( distance( p2, p1 ) == 10.0 );

    REQUIRE( distance( p2, p1 ) == distance( p1, p2 ) );

    p2.move( 10, 0 );
    REQUIRE( distance( p1, p2 ) == 0.0 );
}

TEST_CASE( "Point approximately equals test", "[approximately_equals]" )
{
    Point2D p1( 10, 10 );
    Point2D p2( 10.0001, 10.0001 );

    REQUIRE( ISC::geometry::close_enough( p1, p2 ) );
}

TEST_CASE( "Rectangle Boundary Tests", "[constructor][rectangleBoundary]" )
{
    SECTION( "Constructor Test" )
    {
        RectangleBoundary boundary( 10, 20, { 0, 0 } );
        REQUIRE( boundary.position() == Point2D( 0, 0 ) );
        REQUIRE( boundary.x_dim() == 10 );
        REQUIRE( boundary.y_dim() == 20 );
        REQUIRE( boundary.center() == Point2D( 5, 10 ) );
    }
    SECTION( "Vertices Test" )
    {
        RectangleBoundary boundary( 10, 20, { 0, 0 } );
        auto vertices = boundary.vertices();
        REQUIRE( std::find( vertices.begin(), vertices.end(), Point2D( 0, 0 ) )
                 != vertices.end() );
        REQUIRE( std::find( vertices.begin(), vertices.end(), Point2D( 10, 0 ) )
                 != vertices.end() );
        REQUIRE( std::find( vertices.begin(), vertices.end(), Point2D( 10, 20 ) )
                 != vertices.end() );
        REQUIRE( std::find( vertices.begin(), vertices.end(), Point2D( 0, 20 ) )
                 != vertices.end() );
    }
    SECTION( "isInside function test" )
    {
        RectangleBoundary boundary( 10, 20, { 0, 0 } );
        Point2D inner_point( 5, 10 );
        Point2D outer_point( 30, 30 );
        Point2D edge_point( 10, 5 );
        Point2D corner_point( 10, 20 );
        REQUIRE( isInside( inner_point, boundary ) );
        REQUIRE_FALSE( isInside( outer_point, boundary ) );
        REQUIRE_FALSE( isInside( edge_point, boundary ) );
        REQUIRE_FALSE( isInside( corner_point, boundary ) );
    }
}