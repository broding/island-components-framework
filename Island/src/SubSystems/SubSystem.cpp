//
//  SubSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "SubSystem.h"
#include "Component.h"

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
    for (std::list<EventType>::const_iterator it = _subscribedEvents.begin(), end = _subscribedEvents.end(); it != end; ++it)
    {
        if(*it == event->type)
            ProcessEvent(component, event);
    }
}

std::list<Component*> SubSystem::GetValidComponents()
{
    std::list<Component*> validComponents;
    
    for (std::list<Component*>::const_iterator it = _components.begin(), end = _components.end(); it != end; ++it)
        if((*it)->enabled && (*it)->GetOwner()->addedToScene)
            validComponents.push_back(*it);
    
    return validComponents;
}