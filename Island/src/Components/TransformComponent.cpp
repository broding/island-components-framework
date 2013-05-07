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
	_name = "Transform";
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



void TransformComponent::FillXML(pugi::xml_node &node)
{
	this->AppendDataNode(node, "positionX", position.x);
	this->AppendDataNode(node, "positionY", position.y);
	this->AppendDataNode(node, "scaleX", scale.x);
	this->AppendDataNode(node, "scaleY", scale.y);
	this->AppendDataNode(node, "originX", origin.x);
	this->AppendDataNode(node, "originY", origin.y);
}

void TransformComponent::UpdateFromXML(pugi::xml_node node)
{
    
    position.x = GetXMLData(node, "positionX").as_float();
    position.y = GetXMLData(node, "positionY").as_float();
    scale.x = GetXMLData(node, "scaleX").as_float();
    scale.y = GetXMLData(node, "scaleY").as_float();
    origin.x = GetXMLData(node, "originX").as_float();
    origin.y = GetXMLData(node, "originY").as_float();
}