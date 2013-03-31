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

class BoxCollisionComponent : Component
{
private:
public:
    BoxCollisionComponent();
    
    static CollisionSystem* collisionSystem;
};

#endif /* defined(__Island__BoxCollisionComponent__) */
