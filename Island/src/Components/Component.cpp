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

Component::Component(ComponentType type, std::string name, SubSystem* subSystem)
{
    _type = type;
	_name = name;
    _subSystem = subSystem;
    enabled = true;
    _owner = 0;

    this->AddToSystem();
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

void Component::DrawDebug(sf::RenderWindow *window)
{
    
}

void Component::AppendDataNode(pugi::xml_node &node, std::string name, std::string value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name.c_str());
    dataNode.append_attribute("value").set_value(value.c_str());
}

void Component::AppendDataNode(pugi::xml_node &node, std::string name, bool value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name.c_str());
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, std::string name, int value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name.c_str());
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, std::string name, unsigned int value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");
    
	dataNode.append_attribute("type").set_value(name.c_str());
    dataNode.append_attribute("value").set_value(value);
}

void Component::AppendDataNode(pugi::xml_node &node, std::string name, float value)
{
	pugi::xml_node dataNode;
    dataNode = node.append_child("data");

	dataNode.append_attribute("type").set_value(name.c_str());
    dataNode.append_attribute("value").set_value(value);
}

pugi::xml_attribute Component::GetXMLData(pugi::xml_node &node, std::string data)
{
    for (pugi::xml_node dataNode = node.first_child(); dataNode; dataNode = dataNode.next_sibling())
	{
        if(!strcmp(dataNode.attribute("type").as_string(), data.c_str()))
            return dataNode.attribute("value");
    }
    
    return pugi::xml_attribute();
}
