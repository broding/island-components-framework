//
//  PlayerInputComponent.cpp
//  Island
//
//  Created by Bas Roding on 20-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PlayerInputComponent.h"

PlayerInputSystem* PlayerInputComponent::playerInputSystem;

PlayerInputComponent::PlayerInputComponent() : Component(COMPONENT_PLAYERINPUT, "Player Input", playerInputSystem)
{
    left = sf::Keyboard::A;
    right = sf::Keyboard::D;
    up = sf::Keyboard::W;
    down = sf::Keyboard::S;
    shoot = sf::Keyboard::Space;
}

void PlayerInputComponent::FillXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
}

void PlayerInputComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
