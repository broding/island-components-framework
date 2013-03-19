//
//  TransformComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "TransformComponent.h"
#include "TransformSystem.h"

TransformSystem* TransformComponent::transformSystem;

TransformComponent::TransformComponent()
{
    _type = COMPONENT_TRANSFORM;
    _subSystem = transformSystem;
    transformSystem->AddComponent(this);
    
    scale = sf::Vector2f(1.0f, 1.0f);
    rotation = 0.0f;
    origin = sf::Vector2f(0.0f, 0.0f);
}

TransformComponent::~TransformComponent()
{
    transformSystem->RemoveComponent(this);
}