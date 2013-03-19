//
//  Component.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Component.h"

Component::Component()
{
    _type = COMPONENT_NULL;
}

Component::~Component()
{
    
}

ComponentType Component::GetComponentType()
{
    return _type;
}

Entity* Component::GetOwner()
{
    return _owner;
}

void Component::SetOwner(Entity *entity)
{
    _owner = entity;
}

void Component::HandleEvent(Event* event)
{
    _subSystem->HandleEvent(this, event);
}

void Component::AddComponentSubscription(ComponentType type)
{
    if(_componentSubscriptions.find(type) == _componentSubscriptions.end())
        _componentSubscriptions[type] = 0;
    else
        throw new std::exception();
}

void Component::RemoveComponentSubscription(ComponentType type)
{
    _componentSubscriptions.erase(type);
}

void Component::AddNeighbourComponent(Component *component)
{
    if(_componentSubscriptions.find(component->GetComponentType()) != _componentSubscriptions.end())
        _componentSubscriptions[component->GetComponentType()] = component;
}

void Component::RemoveNeighbourComponent(Component *component)
{
    if(_componentSubscriptions.find(component->GetComponentType()) != _componentSubscriptions.end())
        _componentSubscriptions[component->GetComponentType()] = 0;
}

Component* Component::GetNeighbourComponent(ComponentType type)
{
    return _componentSubscriptions.find(type)->second;
}
