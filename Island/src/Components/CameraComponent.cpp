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
    snapSpeed = 1.5;
}

void CameraComponent::UseCamera()
{
    cameraSystem->currentCamera = this;
}