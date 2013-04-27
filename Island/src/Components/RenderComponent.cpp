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
    
    this->AddToSystem();
    
    this->AddComponentSubscription(COMPONENT_TRANSFORM);
    
    currentFrame = 0;
    currentFrameTime = 0;
    looping = true;
}