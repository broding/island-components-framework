//
//  StructureFactory.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__StructureFactory__
#define __Island__StructureFactory__

#include <iostream>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"

class StructureFactory
{
public:
    static Entity* CreateWall(sf::Vector2f position, float rotation, int length, int width)
    {
        Entity* entity = new Entity();
        TransformComponent* transformComponent = new TransformComponent();
        transformComponent->position = sf::Vector2f(position);
        transformComponent->rotation = rotation;
        PhysicsComponent* physicsComponent = new PhysicsComponent();
        NetworkComponent* networkComponent = new NetworkComponent();
        networkComponent->networkableComponents.push_back(transformComponent);
        BoxCollisionComponent* collisionComponent = new BoxCollisionComponent();
        collisionComponent->center = sf::Vector2f(length / 2, width / 2);
        collisionComponent->size = sf::Vector2f(length, width);

        entity->AddComponent(transformComponent);
        entity->AddComponent(physicsComponent);
        entity->AddComponent(networkComponent);
        entity->AddComponent(collisionComponent);
        
        return entity;
    }
    
    static Entity* CreateSphere(sf::Vector2f position, float radius)
    {
        Entity* entity = new Entity();
        TransformComponent* transformComponent = new TransformComponent();
        transformComponent->position = sf::Vector2f(position);
        PhysicsComponent* physicsComponent = new PhysicsComponent();
        NetworkComponent* networkComponent = new NetworkComponent();
        networkComponent->networkableComponents.push_back(transformComponent);
        SphereCollisionComponent* collisionComponent = new SphereCollisionComponent();
        collisionComponent->center = sf::Vector2f(radius, radius);
        collisionComponent->radius = radius;
        collisionComponent->solid = true;
        
        entity->AddComponent(transformComponent);
        entity->AddComponent(physicsComponent);
        entity->AddComponent(networkComponent);
        entity->AddComponent(collisionComponent);
        
        return entity;
    }
};

#endif /* defined(__Island__StructureFactory__) */
