//
//  BulletFactory.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__BulletFactory__
#define __Island__BulletFactory__

#include <iostream>
#include "Entity.h"
#include "WeaponComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include <SFML/System.hpp>
#include "BulletScript.h"
#include "ScriptComponent.h"
#include "ResourcePath.hpp"
#include "DamageComponent.h"

class BulletFactory
{
public:
    static Entity* CreateBullet(WeaponComponent* component, sf::Vector2f position)
    {
        Entity* entity = new Entity();
        
        RenderComponent* renderComponent = new RenderComponent();
        sf::Texture* texture = new sf::Texture();
        texture->loadFromFile(resourcePath() + "bullet_hole.png");
        texture->setSmooth(true);
        renderComponent->sprite = *new sf::Sprite();
        renderComponent->sprite.setTexture(*texture);

        TransformComponent* transformComponent = new TransformComponent();
        transformComponent->position = sf::Vector2f(position);
        transformComponent->origin = sf::Vector2f(64, 64);
        PhysicsComponent* physicsComponent = new PhysicsComponent();
        SphereCollisionComponent* collisionComponent = new SphereCollisionComponent();
        collisionComponent->collisionGroup = 1;
        collisionComponent->trigger = true;
        ScriptComponent* scriptComponent = new ScriptComponent();
        scriptComponent->script = new BulletScript();
        DamageComponent* damageComponent = new DamageComponent();
        
        entity->AddComponent(renderComponent);
        entity->AddComponent(transformComponent);
        entity->AddComponent(physicsComponent);
        entity->AddComponent(collisionComponent);
        entity->AddComponent(scriptComponent);
        entity->AddComponent(damageComponent);
        
        return entity;
    }
};


#endif /* defined(__Island__BulletFactory__) */
