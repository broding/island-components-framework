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

class BoxCollisionComponent : public Component
{
private:
public:
    BoxCollisionComponent();
    
    static CollisionSystem* collisionSystem;
    
    static sf::FloatRect GetBoundingBox(BoxCollisionComponent box);
    sf::ConvexShape GetConvexShape();
    virtual void DrawDebug(sf::RenderWindow* window);
    
    bool trigger;
    sf::Vector2f center;
    sf::Vector2f size;
    
};

#endif /* defined(__Island__BoxCollisionComponent__) */
