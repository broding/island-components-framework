//
//  Entity.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Entity.h"
#include "Component.h"

Entity::Entity(std::string name) : _name(name)
{
    _scene = NULL;
}

Entity::~Entity()
{
    for (std::list<Component*>::const_iterator it = _components.begin(), end = _components.end(); it != end; ++it)
        delete *it;
}

void Entity::SetParent(Scene *scene)
{
    _scene = scene;
}

Scene* Entity::GetParent()
{
    return _scene;
}

bool Entity::IsAddedToScene()
{
    return _scene != NULL;
}

void Entity::AddComponent(Component *component)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        (*iterator)->AddNeighbourComponent(component);
        component->AddNeighbourComponent(*iterator);
    }
    
    _components.push_back(component);
    component->SetOwner(this);
}

void Entity::RemoveComponent(ComponentType type)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        if((*iterator)->GetComponentType() == type)
        {
            _components.remove(*iterator);
            
            for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
                (*iterator)->RemoveNeighbourComponent(*iterator);
            
            delete *iterator;
        }
    }
}

Component* Entity::GetComponent(ComponentType type)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
        if((*iterator)->GetComponentType() == type)
            return (*iterator);
    
    return NULL;
}

void Entity::HandleEvent(Event* event)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        (*iterator)->HandleEvent(event);
    }
}