//
// Created by aaron on 30/06/18.
//

#include "classification.h"
#include "catch.hpp"

using ISC::geometry::Point2D;
using ISC::clustering::cluster;

TEST_CASE( "Helper Function test", "[avg_slope][sum_sqaured_deviation]" )
{
    SECTION( "avg_slope" )
    {
        cluster clus
            = { Point2D( 0, 0 ), Point2D( 1, 1 ), Point2D( 2, 2 ), Point2D( 4, 4 ) };
        REQUIRE( ISC::classification::avg_slope( clus ) == 1 );

        cluster clus2
            = { Point2D( 0, 0 ), Point2D( 1, 2 ), Point2D( 2, 4 ), Point2D( 3, 6 ) };
        REQUIRE( ISC::classification::avg_slope( clus2 ) == 2 );
    }
}