//
//  TransformComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "TransformComponent.h"
#include "TransformSystem.h"
#include "Entity.h"

#include <SFML/Network.hpp>

TransformSystem* TransformComponent::transformSystem;

TransformComponent::TransformComponent()
{
    _type = COMPONENT_TRANSFORM;
    _subSystem = transformSystem;
    
    this->AddToSystem();
    
    scale = sf::Vector2f(1.0f, 1.0f);
    rotation = 0.0f;
    origin = sf::Vector2f(0.0f, 0.0f);
}

const void* TransformComponent::GenerateNetworkPacket()
{
    sf::Packet packet;
    packet <<
        position.x <<
        position.y <<
        scale.x <<
        scale.y <<
        rotation <<
        origin.x <<
        origin.y;
    
    return packet.getData();
}


void TransformComponent::ApplyNetworkPacket()
{
    
}

void TransformComponent::DrawDebug(sf::RenderWindow *window)
{
    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(16, 16));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2);
    rect.setPosition(position);
    rect.setRotation(rotation);
    rect.setOrigin(8, 8);
    rect.setOutlineColor(sf::Color::Blue);
        
    window->draw(rect);
}



pugi::xml_node TransformComponent::CreateXML(pugi::xml_node &node)
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

void TransformComponent::UpdateFromXML(pugi::xml_node node)
{
    
}