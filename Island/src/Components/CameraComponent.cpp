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
}