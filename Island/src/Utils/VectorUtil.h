//
//  VectorMath.h
//  Island
//
//  Created by Bas Roding on 30-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__VectorUtil__
#define __Island__VectorUtil__

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

class VectorUtil
{
public:
    
    static float Magnitude(const sf::Vector2f vector)
    {
        return sqrt(MagnitudeSquared(vector));
    }
    
    static float MagnitudeSquared(const sf::Vector2f vector)
    {
        return vector.x * vector.x + vector.y * vector.y;
    }
    
    static sf::Vector2f Normalized(const sf::Vector2f vector)
    {
        return vector / Magnitude(vector);
    }
    
    static void Normalize(sf::Vector2f &vector)
    {
        vector = vector / Magnitude(vector);
    }
};

#endif /* defined(__Island__VectorUtil__) */
