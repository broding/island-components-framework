//
//  CollisionSystem.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CollisionSystem.h"

void CollisionSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
}

void CollisionSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}
