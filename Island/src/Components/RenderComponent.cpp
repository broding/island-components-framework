//
//  RenderComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "RenderComponent.h"

RenderSystem* RenderComponent::renderSystem;

RenderComponent::RenderComponent()
{
    _type = COMPONENT_RENDER;
    _subSystem = renderSystem;
    renderSystem->AddComponent(this);
    
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
}

RenderComponent::~RenderComponent()
{
    renderSystem->RemoveComponent(this);
}