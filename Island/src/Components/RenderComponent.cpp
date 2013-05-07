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
	AppendDataNode(node, "Sprite name", "name of sprite in resourcemanager");
	AppendDataNode(node, "Rectangle X", textureRect.left);
	AppendDataNode(node, "Rectangle Y", textureRect.top);
	AppendDataNode(node, "Rectangle Width", textureRect.width);
	AppendDataNode(node, "Rectangle Height", textureRect.height);
	AppendDataNode(node, "Current frame", currentFrame);
	AppendDataNode(node, "Current frame", currentFrameTime);
	AppendDataNode(node, "Looping", looping);
}

void RenderComponent::UpdateFromXML(pugi::xml_node node)
{
    
}