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

class BulletFactory
{
public:
    static Entity* CreateBullet(WeaponComponent* component, sf::Vector2f position)
    {
        Entity* entity = new Entity();
        
        TransformComponent* transformComponent = new TransformComponent();
        transformComponent->position = sf::Vector2f(position);
        PhysicsComponent* physicsComponent = new PhysicsComponent();
        SphereCollisionComponent* collisionComponent = new SphereCollisionComponent();
        collisionComponent->trigger = true;
        
        entity->AddComponent(transformComponent);
        entity->AddComponent(physicsComponent);
        entity->AddComponent(collisionComponent);
        
        return entity;
    }
};


#endif /* defined(__Island__BulletFactory__) */
