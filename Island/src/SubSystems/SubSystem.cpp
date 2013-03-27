//
//  SubSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "SubSystem.h"

SubSystem::~SubSystem()
{
    
}

void SubSystem::AddComponent(Component* component)
{
    _components.push_back(component);
}

void SubSystem::RemoveComponent(Component *component)
{
    _components.remove(component);
}

void SubSystem::HandleEvent(Component *component, Event* event)
{
    for (std::list<EventType>::const_iterator iterator = _subscribedEvents.begin(), end = _subscribedEvents.end(); iterator != end; ++iterator)
    {
        if(*iterator == event->type)
            ProcessEvent(component, event);
    }
}