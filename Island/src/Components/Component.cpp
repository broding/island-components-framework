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
	_name = "no_name_set";
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

std::string  Component::GetName()
{
    return _name;
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

void Component::AppendDataNode(pugi::xml_node &node, pugi::char_t* name, pugi::char_t* value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name);
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, pugi::char_t* name, bool value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name);
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, pugi::char_t* name, int value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name);
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, pugi::char_t* name, float value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name);
    dataNode.append_attribute("value").set_value(value);
}

pugi::xml_attribute Component::GetXMLData(pugi::xml_node &node, std::string data)
{
    for (pugi::xml_node dataNode = node.first_child(); dataNode; dataNode = dataNode.next_sibling())
	{
        std::cout << dataNode.attribute("type").as_string() << std::endl;
        if(!strcmp(dataNode.attribute("type").as_string(), data.c_str()))
            return dataNode.attribute("value");
    }
    
    return pugi::xml_attribute();
}
