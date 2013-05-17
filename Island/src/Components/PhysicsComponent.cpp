//
//  PhysicsComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PhysicsComponent.h"
#include "PhysicsSystem.h"
#include <SFML/System.hpp>

PhysicsSystem* PhysicsComponent::physicsSystem;

PhysicsComponent::PhysicsComponent() : Component(COMPONENT_PHYSICS, "Physics", physicsSystem)
{
    mass = 1;
}

void PhysicsComponent::FillXML(pugi::xml_node &node)
{
    this->AppendDataNode(node, "velocityX", velocity.x);
	this->AppendDataNode(node, "velocityY", velocity.y);
	this->AppendDataNode(node, "accelerationX", velocity.x);
	this->AppendDataNode(node, "accelerationY", velocity.y);
	this->AppendDataNode(node, "mass", mass);
}

void PhysicsComponent::UpdateFromXML(pugi::xml_node node)
{
	velocity.x = GetXMLData(node, "velocityX").as_float();
	velocity.y = GetXMLData(node, "velocityY").as_float();
	acceleration.x = GetXMLData(node, "accelerationX").as_float();
	acceleration.y = GetXMLData(node, "accelerationY").as_float();
	mass = GetXMLData(node, "mass").as_float();
}
