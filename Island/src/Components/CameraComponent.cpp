//
//  CameraComponent.cpp
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CameraComponent.h"

CameraSystem* CameraComponent::cameraSystem;

CameraComponent::CameraComponent()
{
    _type = COMPONENT_CAMERA;
    _subSystem = cameraSystem;
    
    this->AddToSystem();
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
    
    halfSize = sf::Vector2f(1024, 768);
    maxTargetDistance = 25;
    snapSpeed = 0.5;
}

void CameraComponent::UseCamera()
{
    cameraSystem->currentCamera = this;
}



pugi::xml_node CameraComponent::CreateXML()
{
    pugi::xml_node dataNode;
    
    pugi::xml_node node;
    node.set_name("component");
    node.append_attribute("type").set_value("transform");
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    return node;
}

void CameraComponent::UpdateFromXML(pugi::xml_node node)
{
    
}