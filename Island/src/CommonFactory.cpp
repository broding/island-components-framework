//
//  CommonFactory.cpp
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CommonFactory.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "ResourcePath.hpp"

Entity* CommonFactory::CreateSprite(std::string path)
{
    Entity* sprite = new Entity();
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + path);
    texture->setSmooth(true);
    renderComponent->sprite = *new sf::Sprite();
    renderComponent->sprite.setTexture(*texture);
    
    sprite->AddComponent(renderComponent);
    
    return sprite;
}
