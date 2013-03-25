//
//  Core.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Core.h"

#include "RenderSystem.h"
#include "TransformSystem.h"
#include "PhysicsSystem.h"
#include "PlayerInputSystem.h"
#include "NetworkSystem.h"

#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"

#include "Entity.h"
#include "ResourcePath.hpp"

Core::Core(sf::RenderWindow* window)
{
    RenderSystem* renderSystem = new RenderSystem(window);
    TransformSystem* transformSystem = new TransformSystem();
    PhysicsSystem* physicsSystem = new PhysicsSystem();
    PlayerInputSystem* playerInputSystem = new PlayerInputSystem();
    NetworkSystem* networkSystem = new NetworkSystem();
    
    AddSubSystem(playerInputSystem);
    AddSubSystem(physicsSystem);
    AddSubSystem(transformSystem);
    AddSubSystem(renderSystem);
    AddSubSystem(networkSystem);
    
    // setup subsystems in components
    RenderComponent::renderSystem = renderSystem;
    TransformComponent::transformSystem = transformSystem;
    PhysicsComponent::physicsSystem = physicsSystem;
    PlayerInputComponent::playerInputSystem = playerInputSystem;
    NetworkComponent::networkSystem = networkSystem;
    
    Entity* player = new Entity();
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + "icon.png");
    renderComponent->sprite = *new sf::Sprite();
    renderComponent->sprite.setTexture(*texture);
    TransformComponent* transformComponent = new TransformComponent();
    transformComponent->position = sf::Vector2f(40, 40);
    PlayerInputComponent* playerInputComponent = new PlayerInputComponent();
    PhysicsComponent* physicsComponent = new PhysicsComponent();
    NetworkComponent* networkComponent = new NetworkComponent();
    
    player->AddComponent(renderComponent);
    player->AddComponent(transformComponent);
    player->AddComponent(physicsComponent);
    player->AddComponent(playerInputComponent);
    player->AddComponent(networkComponent);
}

Core::~Core()
{
    
}

void Core::AddSubSystem(SubSystem *subSystem)
{
    _subSystems.push_back(subSystem);
}

void Core::Update(float lastFrameTime)
{
    for (std::vector<SubSystem*>::const_iterator iterator = _subSystems.begin(), end = _subSystems.end(); iterator != end; ++iterator)
    {
        (*iterator)->ProcessGameTick(lastFrameTime);
    }
}