//
//  PhysicsComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PhysicsComponent.h"
#include "PhysicsSystem.h"
#include <SFML/System.hpp>

PhysicsSystem* PhysicsComponent::physicsSystem;

PhysicsComponent::PhysicsComponent()
{
    _type = COMPONENT_PHYSICS;
    _subSystem = physicsSystem;
    
    this->AddToSystem();
    
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
    
    mass = 1;
}
