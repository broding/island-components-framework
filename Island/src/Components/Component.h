//
//  Component.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Component__
#define __Island__Component__

#include <iostream>
#include <map>

#include "Event.h"
#include "SubSystem.h"
#include "ComponentType.h"
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"

class Entity;

class Component
{
private:
    Entity* _owner;
protected:
    ComponentType _type;
	std::string _name;
    SubSystem* _subSystem;
    std::map<ComponentType, Component*> _componentSubscriptions;
    
	void AppendDataNode(pugi::xml_node &node, std::string name, std::string value);
	void AppendDataNode(pugi::xml_node &node, std::string name, bool value);
	void AppendDataNode(pugi::xml_node &node, std::string name, unsigned int value);
	void AppendDataNode(pugi::xml_node &node, std::string name, int value);
	void AppendDataNode(pugi::xml_node &node, std::string name, float value);
    pugi::xml_attribute GetXMLData(pugi::xml_node &node, std::string data);

    bool IsSubscribedTo(ComponentType type);
public:
    Component(ComponentType type, std::string name, SubSystem* subSystem);
    virtual ~Component();
    void AddToSystem();
    void RemoveFromSystem();
    ComponentType GetComponentType();
	std::string GetName();
    void SetOwner(Entity* entity);
    Entity* GetOwner();
    void HandleEvent(Event* event);
    virtual void DrawDebug(sf::RenderWindow* window);
    virtual void FillXML(pugi::xml_node &node) = 0;
    virtual void UpdateFromXML(pugi::xml_node node) = 0;
    
    bool enabled;
};

#endif /* defined(__Island__Component__) */
