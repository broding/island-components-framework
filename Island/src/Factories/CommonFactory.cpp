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
#include "PhysicsComponent.h"
#include "CameraComponent.h"
#include "ResourcePath.hpp"

Entity* CommonFactory::CreateSprite(std::string path)
{
    Entity* sprite = new Entity();
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + path);
    texture->setSmooth(true);
    renderComponent->sprite = *new Sprite();
    renderComponent->sprite.setTexture(*texture);
    
    sprite->AddComponent(renderComponent);
    
    return sprite;
}

Entity* CommonFactory::CreateCamera()
{
    Entity* camera = new Entity();
    TransformComponent* transformComponent = new TransformComponent();
    PhysicsComponent* physicsComponent = new PhysicsComponent();
    CameraComponent* cameraComponent = new CameraComponent();
    cameraComponent->UseCamera();
    
    camera->AddComponent(physicsComponent);
    camera->AddComponent(cameraComponent);
    camera->AddComponent(transformComponent);
    
    return camera;
}
