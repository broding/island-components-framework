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
#include "Entity.h"

RenderSystem::RenderSystem(sf::RenderWindow* renderWindow) : _renderWindow(renderWindow)
{
}

RenderSystem::~RenderSystem()
{
    
}

void RenderSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        RenderComponent* renderComponent = static_cast<RenderComponent*>(*iterator);
        TransformComponent* transformComponent = renderComponent->GetOwner()->GetComponent<TransformComponent>();
        
        sf::IntRect originalRect = renderComponent->sprite.getTextureRect();
        
        if(transformComponent != 0)
        {
            renderComponent->sprite.setPosition(transformComponent->position);
            renderComponent->sprite.setScale(transformComponent->scale);
            renderComponent->sprite.setRotation(transformComponent->rotation);
            renderComponent->sprite.setOrigin(transformComponent->origin);
        }
        
        if(renderComponent->currentAnimation != 0)
        {
            Animation* animation = renderComponent->currentAnimation;
            animation->currentFrameTime += lastFrameTime;
            
            if(animation->currentFrameTime > renderComponent->currentAnimation->frames[animation->currentFrame].time)
            {
                if(animation->currentFrame >= animation->frames.size() - 1 && animation->looping)
                    animation->currentFrame = 0;
                else if(animation->currentFrame < animation->frames.size())
                    animation->currentFrame++;
                
                animation->currentFrameTime = 0;
            }
            
            renderComponent->animationRect.left = renderComponent->animationRect.width * animation->currentFrame + originalRect.left;
            renderComponent->sprite.setTextureRect(renderComponent->animationRect);
        }
        
        float spriteX = renderComponent->sprite.getPosition().x;
        float spriteY = renderComponent->sprite.getPosition().y;
        float spriteWidth = renderComponent->sprite.getScale().x * renderComponent->sprite.getTextureRect().width;
        float spriteHeight = renderComponent->sprite.getScale().y * renderComponent->sprite.getTextureRect().height;
        
        for(unsigned int x = 0; x < renderComponent->tiling.x; x++)
        {
            for(unsigned int y = 0; y < renderComponent->tiling.y; y++)
            {
                renderComponent->sprite.setPosition(spriteX + spriteWidth * x, spriteY + spriteHeight * y);
                _renderWindow->draw(renderComponent->sprite);
            }
        }
        
        renderComponent->sprite.setTextureRect(originalRect);
    }
}

