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
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "ResourcePath.hpp"

Core::Core(sf::RenderWindow* window)
{
    RenderSystem* renderSystem = new RenderSystem(window);
    TransformSystem* transformSystem = new TransformSystem();
    
    AddSubSystem(renderSystem);
    AddSubSystem(transformSystem);
    
    // setup subsystems in components
    RenderComponent::renderSystem = renderSystem;
    TransformComponent::transformSystem = transformSystem;
    
    Entity* player = new Entity();
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + "icon.png");
    renderComponent->sprite = *new sf::Sprite();
    renderComponent->sprite.setTexture(*texture);
    TransformComponent* transformComponent = new TransformComponent();
    transformComponent->position = sf::Vector2f(40, 40);
    
    player->AddComponent(renderComponent);
    player->AddComponent(transformComponent);
}

Core::~Core()
{
    
}

void Core::AddSubSystem(SubSystem *subSystem)
{
    _subSystems.push_back(subSystem);
}

void Core::Update(double lastFrameTime)
{
    for (std::vector<SubSystem*>::const_iterator iterator = _subSystems.begin(), end = _subSystems.end(); iterator != end; ++iterator)
    {
        (*iterator)->ProcessGameTick(lastFrameTime);
    }
}