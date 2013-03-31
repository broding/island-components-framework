//
//  ConvexShape.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ConvexShape.h"
#include <SFML/Graphics.hpp>

ConvexShape::ConvexShape()
{
    
}

void ConvexShape::Rotate(float angle)
{
    sf::Transform transform;
    transform.rotate(angle, center);
    
    for (std::vector<sf::Vector2f>::iterator it = vertices.begin(), end = vertices.end(); it != end; ++it)
    {
        *it = transform.transformPoint(*it);
    }
}