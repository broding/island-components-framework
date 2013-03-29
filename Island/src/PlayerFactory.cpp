//
//  PlayerFactory.cpp
//  Island
//
//  Created by Bas Roding on 28-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PlayerFactory.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"
#include "ResourcePath.hpp"

Entity* PlayerFactory::CreatePlayer()
{
    Entity* player = new Entity();
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + "player.png");
    texture->setSmooth(true);
    renderComponent->sprite = *new sf::Sprite();
    renderComponent->sprite.setTexture(*texture);
    TransformComponent* transformComponent = new TransformComponent();
    transformComponent->position = sf::Vector2f(40, 40);
    transformComponent->origin = sf::Vector2f(32, 29);
    PlayerInputComponent* playerInputComponent = new PlayerInputComponent();
    PhysicsComponent* physicsComponent = new PhysicsComponent();
    NetworkComponent* networkComponent = new NetworkComponent();
    networkComponent->networkableComponents.push_back(transformComponent);
    
    player->AddComponent(renderComponent);
    player->AddComponent(transformComponent);
    player->AddComponent(physicsComponent);
    player->AddComponent(playerInputComponent);
    player->AddComponent(networkComponent);
    
    return player;
}