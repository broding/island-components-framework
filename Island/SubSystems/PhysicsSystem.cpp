//
//  PhysicsSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PhysicsSystem.h"

void PhysicsSystem::ProcessGameTick(double lastFrameTime)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        
    }
}

void PhysicsSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}