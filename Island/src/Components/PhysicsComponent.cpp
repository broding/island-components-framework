//
//  PhysicsComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PhysicsComponent.h"
#include "PhysicsSystem.h"
#include <SFML/System.hpp>

PhysicsSystem* PhysicsComponent::physicsSystem;

PhysicsComponent::PhysicsComponent() : Component(COMPONENT_PHYSICS, "Physics", physicsSystem)
{
    mass = 1;
}



void PhysicsComponent::FillXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("velocity");
    dataNode.append_attribute("value").set_value(145);
}

void PhysicsComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
