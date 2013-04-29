//
//  SubSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "SubSystem.h"
#include "Component.h"
#include "Entity.h"

SubSystem::~SubSystem()
{
    for(int i = 0; i < EVENT_LAST_TYPE; i++)
        _subscribedEvents[i] = false;
}

void SubSystem::SubscribeToEvent(EventType type)
{
    _subscribedEvents[type] = true;
}

void SubSystem::UnsubscribeToEvent(EventType type)
{
    _subscribedEvents[type] = false;
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
    if(_subscribedEvents[event->type])
            ProcessEvent(component, event);
}

std::list<Component*> SubSystem::GetValidComponents()
{
    std::list<Component*> validComponents;
    
    for (std::list<Component*>::const_iterator it = _components.begin(), end = _components.end(); it != end; ++it)
        if((*it)->enabled && (*it)->GetOwner()->IsAddedToScene() && (*it)->GetOwner()->enabled)
            validComponents.push_back(*it);
    
    return validComponents;
}

void SubSystem::DrawDebug(sf::RenderWindow* window)
{
    std::list<Component*> validComponents = GetValidComponents();
    
    for (std::list<Component*>::const_iterator it = validComponents.begin(), end = validComponents.end(); it != end; ++it)
        (*it)->DrawDebug(window);
}

void SubSystem::ProcessEvent(Component *component, Event* event)
{
    
}