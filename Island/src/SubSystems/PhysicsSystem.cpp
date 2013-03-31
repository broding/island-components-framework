//
//  PhysicsSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PhysicsSystem.h"

void PhysicsSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        PhysicsComponent* physicsComponent = static_cast<PhysicsComponent*>(*iterator);
        TransformComponent* transformComponent = static_cast<TransformComponent*>(physicsComponent->GetNeighbourComponent(COMPONENT_TRANSFORM));
        
        if(transformComponent != 0)
            this->Integrate(physicsComponent, transformComponent, lastFrameTime);
    }
}

void PhysicsSystem::Integrate(PhysicsComponent* physicsComponent, TransformComponent* transformComponent, float lastFrameTime)
{
    // update position
    transformComponent->previousPosition = transformComponent->position;
    transformComponent->previousRotation = transformComponent->rotation;
    
    transformComponent->position += physicsComponent->velocity * lastFrameTime;
    
    // update the acceleration with the accumulated forces and inverse mass
    sf::Vector2f resultingAcceleration = physicsComponent->acceleration;
    resultingAcceleration += physicsComponent->forceAccumulated * (1 / physicsComponent->mass);
    
    physicsComponent->velocity += resultingAcceleration * lastFrameTime;
    
    // simulate damping
    physicsComponent->velocity *= 0.999f;
    
    physicsComponent->forceAccumulated = sf::Vector2f(0,0);
}

void PhysicsSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}