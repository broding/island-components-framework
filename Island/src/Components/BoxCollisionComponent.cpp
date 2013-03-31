//
//  BoxCollisionComponent.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "BoxCollisionComponent.h"

CollisionSystem* BoxCollisionComponent::collisionSystem;

BoxCollisionComponent::BoxCollisionComponent()
{
    _type = COMPONENT_BOXCOLLISION;
    _subSystem = collisionSystem;
    
    this->AddToSystem();
}