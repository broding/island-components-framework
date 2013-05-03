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



pugi::xml_node RenderComponent::CreateXML()
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

void RenderComponent::UpdateFromXML(pugi::xml_node node)
{
    
}