//
//  PlayerInputSystem.cpp
//  Island
//
//  Created by Bas Roding on 20-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PlayerInputSystem.h"

#include <SFML/Window/Keyboard.hpp>
#include "PlayerInputComponent.h"
#include "PhysicsComponent.h"

void PlayerInputSystem::ProcessGameTick(float lastFrameTime)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        PlayerInputComponent* inputComponent = static_cast<PlayerInputComponent*>(*iterator);
        PhysicsComponent* physicsComponent = static_cast<PhysicsComponent*>(inputComponent->GetNeighbourComponent(COMPONENT_PHYSICS));
        
        if(physicsComponent != 0)
        {
            if(sf::Keyboard::isKeyPressed(inputComponent->up))
                physicsComponent->forceAccumulated += sf::Vector2f(0, -50);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->down))
                physicsComponent->forceAccumulated += sf::Vector2f(0, 50);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->left))
                physicsComponent->forceAccumulated += sf::Vector2f(-50, 0);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->right))
                physicsComponent->forceAccumulated += sf::Vector2f(50, 0);
        }
    }
}

void PlayerInputSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}