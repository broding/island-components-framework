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

PhysicsComponent::PhysicsComponent()
{
    _type = COMPONENT_PHYSICS;
    _subSystem = physicsSystem;
    
    this->AddToSystem();
    
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
    
    mass = 1;
}



pugi::xml_node PhysicsComponent::CreateXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
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

void PhysicsComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
