//
//  SphereCollisionComponent.cpp
//  Island
//
//  Created by Bas Roding on 01-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "SphereCollisionComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

CollisionSystem* SphereCollisionComponent::collisionSystem;

SphereCollisionComponent::SphereCollisionComponent()
{
    _type = COMPONENT_SPHERECOLLISION;
    _subSystem = collisionSystem;
    
    this->AddToSystem();
    
    radius = 32;
    center = sf::Vector2f(32, 32);
}

void SphereCollisionComponent::DrawDebug(sf::RenderWindow *window)
{
    TransformComponent* transform = this->GetOwner()->GetComponent<TransformComponent>();
    
    if(transform != NULL)
    {
        sf::CircleShape circle = sf::CircleShape(radius);
        circle.setFillColor(sf::Color(255, 0, 0, 100));
        circle.setOutlineThickness(2);
        circle.setPosition(transform->position);
        circle.setOrigin(center);
        circle.setOutlineColor(sf::Color::Red);
        circle.setRotation(transform->rotation);
        
        window->draw(circle);
    }
}
