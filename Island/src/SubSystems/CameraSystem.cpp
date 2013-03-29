//
//  CameraSystem.cpp
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CameraSystem.h"
#include "CameraComponent.h"

CameraSystem::CameraSystem()
{
    
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
    }
}

void CameraSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}