//
//  SphereCollisionComponent.h
//  Island
//
//  Created by Bas Roding on 01-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__SphereCollisionComponent__
#define __Island__SphereCollisionComponent__

#include <iostream>
#include "Component.h"
#include "CollisionSystem.h"
#include "ICollisionComponent.h"

class SphereCollisionComponent : public Component, public ICollisionComponent
{
private:
public:
    SphereCollisionComponent();
    
    static CollisionSystem* collisionSystem;
    
    sf::ConvexShape GetConvexShape();
    virtual void DrawDebug(sf::RenderWindow* window);
    
    float radius;
    sf::Vector2f center;
    
};

#endif /* defined(__Island__SphereCollisionComponent__) */
