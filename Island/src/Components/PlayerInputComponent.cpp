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
    playerInputSystem->AddComponent(this);
    
        this->AddComponentSubscription(COMPONENT_PHYSICS);
    
    left = sf::Keyboard::A;
    right = sf::Keyboard::D;
    up = sf::Keyboard::W;
    down = sf::Keyboard::S;
}

PlayerInputComponent::~PlayerInputComponent()
{
    playerInputSystem->RemoveComponent(this);
}
