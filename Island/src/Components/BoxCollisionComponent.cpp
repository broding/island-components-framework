//
//  BoxCollisionComponent.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "BoxCollisionComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

CollisionSystem* BoxCollisionComponent::collisionSystem;

BoxCollisionComponent::BoxCollisionComponent()
{
    _type = COMPONENT_BOXCOLLISION;
    _subSystem = collisionSystem;
    
    this->AddToSystem();
    
    center = sf::Vector2f(32,32);
    size = sf::Vector2f(64, 64);
    trigger = false;
    solid = false;
    collisionGroup = 0;
    collisionGroups[0] = true;
    
    for(int i = 1; i < 20; i++)
        collisionGroups[i] = false;
}

void BoxCollisionComponent::DrawDebug(sf::RenderWindow *window)
{
    TransformComponent* transform = this->GetOwner()->GetComponent<TransformComponent>();
    
    if(transform != NULL)
    {
        sf::RectangleShape rect = sf::RectangleShape(size);
        rect.setFillColor(sf::Color(255, 0, 0, 100));
        rect.setOutlineThickness(2);
        rect.setPosition(transform->position);
        rect.setOrigin(center);
        rect.setOutlineColor(sf::Color::Red);
        rect.setRotation(transform->rotation);
        
        window->draw(rect);
    }
}

sf::ConvexShape BoxCollisionComponent::GetConvexShape()
{
    sf::ConvexShape shape(4);
    TransformComponent* transformComponent = this->GetOwner()->GetComponent<TransformComponent>();
    
    sf::FloatRect rect(0, 0, size.x, size.y);
    sf::Transform transform;
    transform.translate(transformComponent->position);
    transform.rotate(transformComponent->rotation);
    transform.translate(-center);
    
    shape.setPoint(1, transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top)));
    shape.setPoint(2, transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height)));
    shape.setPoint(0, transform.transformPoint(sf::Vector2f(rect.left, rect.top)));
    shape.setPoint(3, transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height)));
    
    
    return shape;
    
}



void BoxCollisionComponent::FillXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("velocity");
    dataNode.append_attribute("value").set_value(145);
}

void BoxCollisionComponent::UpdateFromXML(pugi::xml_node node)
{
    
}