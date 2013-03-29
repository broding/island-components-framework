//
//  TransformSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "TransformSystem.h"
#include "TransformComponent.h"
#include "Event.h"

void TransformSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
}

void TransformSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}