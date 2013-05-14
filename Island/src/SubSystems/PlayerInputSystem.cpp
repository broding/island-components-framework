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
#include "TransformComponent.h"
#include "WeaponComponent.h"
#include "GUIObject.h"
#include "Entity.h"
#include <math.h>
#include "WeaponEvents.h"
#include "GameConfig.h"

PlayerInputSystem::PlayerInputSystem(sf::RenderWindow* window) : _window(window)
{
    
}

void PlayerInputSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    if(GameConfig::GetInstance()->GetFlagConfig("editorMode"))
       return;
       
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        PlayerInputComponent* inputComponent = static_cast<PlayerInputComponent*>(*iterator);
        PhysicsComponent* physicsComponent = inputComponent->GetOwner()->GetComponent<PhysicsComponent>();
        TransformComponent* transformComponent = inputComponent->GetOwner()->GetComponent<TransformComponent>();
        WeaponComponent* weaponComponent = inputComponent->GetOwner()->GetComponent<WeaponComponent>();
        
        if(physicsComponent != NULL)
        {
            int speed = 30;
            if(sf::Keyboard::isKeyPressed(inputComponent->up))
                physicsComponent->forceAccumulated += sf::Vector2f(0, -speed);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->down))
                physicsComponent->forceAccumulated += sf::Vector2f(0, speed);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->left))
                physicsComponent->forceAccumulated += sf::Vector2f(-speed, 0);
            
            if(sf::Keyboard::isKeyPressed(inputComponent->right))
                physicsComponent->forceAccumulated += sf::Vector2f(speed, 0);
        }
        
        if(transformComponent != NULL)
        {
            sf::Vector2i mousePosition = sf::Vector2i(sf::Mouse::getPosition(*GUIObject::window).x, sf::Mouse::getPosition(*GUIObject::window).y);
            sf::Vector2f mouseDelta = _window->mapPixelToCoords(mousePosition) - transformComponent->position;
            const double degreesPerRadian = 57.2957;
            //transformComponent->rotation = atan2(mouseDelta.x, -mouseDelta.y) * degreesPerRadian;
        }
        
        if(weaponComponent != NULL)
        {
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*GUIObject::window).x, sf::Mouse::getPosition(*GUIObject::window).y);
            
            mousePosition = _window->mapPixelToCoords(sf::Vector2i(mousePosition));
            
            if(sf::Keyboard::isKeyPressed(inputComponent->shoot))
            {
                ShootEvent event(mousePosition, weaponComponent);
                inputComponent->GetOwner()->HandleEvent(&event);
            }
        }
    }
}