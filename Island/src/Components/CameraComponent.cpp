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
    
	targetEntity = NULL;
    zoom = 1.0f;
    maxTargetDistance = 25;
    snapSpeed = 0.5;
}

void CameraComponent::UseCamera()
{
    cameraSystem->currentCamera = this;
}



void CameraComponent::FillXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("velocity");
    dataNode.append_attribute("value").set_value(145);
}

void CameraComponent::UpdateFromXML(pugi::xml_node node)
{
    
}