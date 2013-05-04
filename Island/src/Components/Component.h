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
    
	void AppendDataNode(pugi::xml_node &node, pugi::char_t* name, pugi::char_t* value);
	void AppendDataNode(pugi::xml_node &node, pugi::char_t* name, bool value);
	void AppendDataNode(pugi::xml_node &node, pugi::char_t* name, int value);
	void AppendDataNode(pugi::xml_node &node, pugi::char_t* name, float value);
    pugi::xml_attribute GetXMLData(pugi::xml_node &node, std::string data);

    bool IsSubscribedTo(ComponentType type);
public:
    Component();
    virtual ~Component();
    void AddToSystem();
    void RemoveFromSystem();
    ComponentType GetComponentType();
	std::string GetName();
    void SetOwner(Entity* entity);
    Entity* GetOwner();
    void HandleEvent(Event* event);
    void AddComponentSubscription(ComponentType type);
    void RemoveComponentSubscription(ComponentType type);
    void AddNeighbourComponent(Component* component);
    void RemoveNeighbourComponent(Component* component);
    Component* GetNeighbourComponent(ComponentType type);
    virtual void DrawDebug(sf::RenderWindow* window);
    virtual pugi::xml_node CreateXML(pugi::xml_node &node) = 0;
    virtual void UpdateFromXML(pugi::xml_node node) = 0;
    
    bool enabled;
};

#endif /* defined(__Island__Component__) */
