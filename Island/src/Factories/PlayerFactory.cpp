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
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "WeaponComponent.h"
#include "ResourcePath.hpp"
#include "PlayerAnimationScript.h"
#include "ScriptComponent.h"
#include "HealthComponent.h"

Entity* PlayerFactory::CreatePlayer()
{
    Entity* player = new Entity();
    
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + "player2.png");
    texture->setSmooth(true);
    renderComponent->sprite = *new sf::Sprite();
    renderComponent->sprite.setTexture(*texture);
    renderComponent->textureRect = sf::Rect<int>(0, 0, 110, 128);
    
    Animation animation("walk");
    animation.frames.push_back(AnimationFrame(0, 0.1f));
    animation.frames.push_back(AnimationFrame(1, 0.1f));
    animation.frames.push_back(AnimationFrame(0, 0.1f));
    animation.frames.push_back(AnimationFrame(3, 0.1f));
    renderComponent->animations.push_back(animation);
    
    animation = Animation("idle");
    animation.looping = true;
    animation.frames.push_back(AnimationFrame(0, 1.0f));
    renderComponent->animations.push_back(animation);
    
    TransformComponent* transformComponent = new TransformComponent();
    transformComponent->position = sf::Vector2f(40, 40);
    transformComponent->origin = sf::Vector2f(64, 64);
    PlayerInputComponent* playerInputComponent = new PlayerInputComponent();
    PhysicsComponent* physicsComponent = new PhysicsComponent();
    NetworkComponent* networkComponent = new NetworkComponent();
    networkComponent->networkableComponents.push_back(transformComponent);
    SphereCollisionComponent* collisionComponent = new SphereCollisionComponent();
    WeaponComponent* weaponComponent = new WeaponComponent();
    
    ScriptComponent* scriptComponent = new ScriptComponent();
    scriptComponent->script = new PlayerAnimationScript();
    
    HealthComponent* healthComponent = new HealthComponent();
    
    player->AddComponent(renderComponent);
    player->AddComponent(transformComponent);
    player->AddComponent(physicsComponent);
    player->AddComponent(playerInputComponent);
    player->AddComponent(networkComponent);
    player->AddComponent(collisionComponent);
    player->AddComponent(weaponComponent);
    player->AddComponent(scriptComponent);
    player->AddComponent(healthComponent);
    
    return player;
}