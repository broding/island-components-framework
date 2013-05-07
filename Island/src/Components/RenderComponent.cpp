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
    
    tiling = sf::Vector2<unsigned int>(1,1);
    currentFrame = 0;
    currentFrameTime = 0;
    looping = true;
}

RenderComponent::~RenderComponent()
{
    delete sprite.getTexture();
}



void RenderComponent::FillXML(pugi::xml_node &node)
{
	AppendDataNode(node, "position", 145);
	AppendDataNode(node, "velocity", 145);
}

void RenderComponent::UpdateFromXML(pugi::xml_node node)
{
    
}