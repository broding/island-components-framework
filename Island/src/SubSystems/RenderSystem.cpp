//
//  RenderSystem.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "RenderSystem.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include <SFML/Graphics.hpp>

RenderSystem::RenderSystem(sf::RenderWindow* renderWindow) : _renderWindow(renderWindow)
{
}

RenderSystem::~RenderSystem()
{
    
}

void RenderSystem::ProcessGameTick(float lastFrameTime)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(*iterator);
        TransformComponent* transformComponent = static_cast<TransformComponent*>(renderComponent->GetNeighbourComponent(COMPONENT_TRANSFORM));
        
        if(transformComponent != 0)
        {
            renderComponent->sprite.setPosition(transformComponent->position);
            renderComponent->sprite.setScale(transformComponent->scale);
            renderComponent->sprite.setRotation(transformComponent->rotation);
            renderComponent->sprite.setOrigin(transformComponent->origin);
        }
        
        _renderWindow->draw(renderComponent->sprite);
    }
}

void RenderSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}

