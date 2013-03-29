//
//  TransformComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "TransformComponent.h"
#include "TransformSystem.h"

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