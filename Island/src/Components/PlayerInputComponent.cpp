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
}
