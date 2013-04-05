//
//  main.cpp
//  UnitTests
//
//  Created by Bas Roding on 05-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VectorUtil.h"
#include "Projection.h"

TEST_CASE("VectorUtil", "Utility classes for vectors")
{
    sf::Vector2f vector(10, 5);
    REQUIRE(VectorUtil::Magnitude(vector) == 125);
    REQUIRE(VectorUtil::MagnitudeSquared(vector) == 11.18033989f);
}

TEST_CASE("Projection", "..")
{
    Projection p1(3, 5);
    Projection p2(4, 5);
    REQUIRE(p1.IsOverlapping(p2) == true);
    REQUIRE(p1.GetOverlap(p2) == 1);
    
    p1.min = 1;
    p1.max = 10;
    p2.min = 2;
    p2.max = 5;
    
    REQUIRE(p1.IsOverlapping(p2) == true);
    REQUIRE(p1.GetOverlap(p2) == 3);
    
    p1.min = 1;
    p1.max = 5;
    p2.min = 6;
    p2.max = 9;
    
    REQUIRE(p1.IsOverlapping(p2) == false);
    REQUIRE(p1.GetOverlap(p2) == -1);
    
    p1.min = 2;
    p1.max = 3;
    p2.min = 1;
    p2.max = 5;
    
    REQUIRE(p1.IsOverlapping(p2) == true);
    REQUIRE(p1.GetOverlap(p2) == 1);
    
    p1.min = 5;
    p1.max = 8;
    p2.min = 1;
    p2.max = 5;
    
    REQUIRE(p1.IsOverlapping(p2) == false);
    REQUIRE(p1.GetOverlap(p2) == 0);
}
