//
//  BoxCollisionComponent.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__BoxCollisionComponent__
#define __Island__BoxCollisionComponent__

#include <iostream>
#include "Component.h"
#include "CollisionSystem.h"
#include "ConvexShape.h"
#include "ICollisionComponent.h"

class BoxCollisionComponent : public Component, public ICollisionComponent
{
private:
public:
    BoxCollisionComponent();
    
    static CollisionSystem* collisionSystem;
    
    virtual sf::ConvexShape GetConvexShape();
    virtual void DrawDebug(sf::RenderWindow* window);
    
    sf::Vector2f center;
    sf::Vector2f size;
    
};

#endif /* defined(__Island__BoxCollisionComponent__) */
