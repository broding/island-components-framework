//
//  HealthComponent.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "HealthComponent.h"

HealthSystem* HealthComponent::healthSystem;


HealthComponent::HealthComponent()
{
    _type = COMPONENT_HEALTH;
    _subSystem = healthSystem;
    
    this->AddToSystem();
    
    health = 100;
    maxHealth = 100;
    regenRate = 0;
}



void HealthComponent::FillXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("velocity");
    dataNode.append_attribute("value").set_value(145);
}

void HealthComponent::UpdateFromXML(pugi::xml_node node)
{
    
}


