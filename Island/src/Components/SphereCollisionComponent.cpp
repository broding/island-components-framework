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

SphereCollisionComponent::SphereCollisionComponent() : Component(COMPONENT_SPHERECOLLISION, "Sphere Collision", collisionSystem)
{
    radius = 32;
    center = sf::Vector2f(32, 32);
    trigger = false;
    solid = false;
    collisionGroup = 0;
    collisionGroups[0] = true;
    
    for(int i = 1; i < 20; i++)
        collisionGroups[i] = false;
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

sf::ConvexShape SphereCollisionComponent::GetConvexShape()
{
    sf::ConvexShape shape(4);
    TransformComponent* transformComponent = this->GetOwner()->GetComponent<TransformComponent>();
    
    sf::FloatRect rect(0, 0, radius * 2, radius * 2);
    sf::Transform transform;
    transform.translate(transformComponent->position);
    transform.rotate(-45);
    transform.translate(-center);
    
    shape.setPoint(0, transform.transformPoint(sf::Vector2f(rect.left, rect.top)));
    shape.setPoint(1, transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top)));
    shape.setPoint(2, transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height)));
    shape.setPoint(3, transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height)));
    
    
    return shape;
}



void SphereCollisionComponent::FillXML(pugi::xml_node &node)
{
    AppendDataNode(node, "Radius", radius);
	AppendDataNode(node, "Center X", center.x);
	AppendDataNode(node, "Center Y", center.y);
	AppendDataNode(node, "Trigger", trigger);
	AppendDataNode(node, "Collision Group", collisionGroup);
}

void SphereCollisionComponent::UpdateFromXML(pugi::xml_node node)
{
	radius = GetXMLData(node, "Radius").as_float();
	center = sf::Vector2f(GetXMLData(node, "Center X").as_float(), GetXMLData(node, "Center Y").as_float());
	trigger = GetXMLData(node, "Trigger").as_bool();
	collisionGroup = GetXMLData(node, "Collision Group").as_int();
}
