//
//  ICollisionComponent.h
//  Island
//
//  Created by Bas Roding on 01-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ICollisionComponent__
#define __Island__ICollisionComponent__

#include <iostream>

class ICollisionComponent
{
public:
    virtual sf::ConvexShape GetConvexShape() = 0;
    
    bool trigger;
    bool solid;
    bool collisionGroups[20];
    int collisionGroup;
};

#endif /* defined(__Island__ICollisionComponent__) */
