//
//  PlayerInputComponent.cpp
//  Island
//
//  Created by Bas Roding on 20-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PlayerInputComponent.h"

PlayerInputSystem* PlayerInputComponent::playerInputSystem;

PlayerInputComponent::PlayerInputComponent()
{
    _type = COMPONENT_PLAYERINPUT;
    _subSystem = playerInputSystem;
    
    this->AddToSystem();
    
    this->AddComponentSubscription(COMPONENT_PHYSICS);
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
    
    left = sf::Keyboard::A;
    right = sf::Keyboard::D;
    up = sf::Keyboard::W;
    down = sf::Keyboard::S;
    shoot = sf::Keyboard::Space;
}



pugi::xml_node PlayerInputComponent::CreateXML(pugi::xml_node &node)
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

void PlayerInputComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
