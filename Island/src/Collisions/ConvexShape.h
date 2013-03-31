//
//  ConvexShape.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ConvexShape__
#define __Island__ConvexShape__

#include <iostream>
#include <vector>
#include <SFML/System.hpp>

class ConvexShape
{
public:
    ConvexShape();
    
    void Rotate(float angle);
    
    sf::Vector2f center;
    std::vector<sf::Vector2f> vertices;
};

#endif /* defined(__Island__ConvexShape__) */
