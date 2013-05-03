//
//  Component.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Component.h"
#include "Entity.h"
#include <exception>
#include "pugixml.hpp"
#include "ResourcePath.hpp"

Component::Component()
{
    _type = COMPONENT_NULL;
    enabled = true;
}

Component::~Component()
{
    RemoveFromSystem();
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

void Component::AddToSystem()
{
    _subSystem->AddComponent(this);
}

void Component::RemoveFromSystem()
{
    _subSystem->RemoveComponent(this);
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
    if(IsSubscribedTo(type))
        return _componentSubscriptions.find(type)->second;
    else
        throw std::exception();
}

bool Component::IsSubscribedTo(ComponentType type)
{
    return _componentSubscriptions.find(type) != _componentSubscriptions.end();
}

void Component::DrawDebug(sf::RenderWindow *window)
{
    
}

pugi::xml_node Component::CreateXML()
{
    pugi::xml_node dataNode;
    
    pugi::xml_node node;
    node.set_name("component");
    node.append_attribute("type").set_value("transform");
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    return node;
}

void Component::UpdateFromXML(pugi::xml_node node)
{
    
}
