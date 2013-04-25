//
//  HealthSystem.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "HealthSystem.h"

void HealthSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
}

void HealthSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}