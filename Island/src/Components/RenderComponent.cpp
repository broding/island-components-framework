//
//  RenderComponent.cpp
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "RenderComponent.h"
#include "ResourceManager.h"
#include <string>

RenderSystem* RenderComponent::renderSystem;

RenderComponent::RenderComponent() : Component(COMPONENT_RENDER, "Render", renderSystem)
{
    tiling = sf::Vector2<unsigned int>(1,1);
    currentAnimation = 0;
}

RenderComponent::~RenderComponent()
{
    delete sprite.getTexture();
}

void RenderComponent::SetAnimation(std::string name)
{
    for (std::vector<Animation>::iterator it = animations.begin(), end = animations.end(); it != end; ++it)
    {
        if((*it).name == name)
            currentAnimation = &(*it);
    }
}

void RenderComponent::FillXML(pugi::xml_node &node)
{
	AppendDataNode(node, "Sprite name", sprite.getName());
	AppendDataNode(node, "Rectangle X", animationRect.left);
	AppendDataNode(node, "Rectangle Y", animationRect.top);
	AppendDataNode(node, "Rectangle Width", animationRect.width);
	AppendDataNode(node, "Rectangle Height", animationRect.height);
}

void RenderComponent::UpdateFromXML(pugi::xml_node node)
{
    if(sprite.getName().compare(GetXMLData(node, "Sprite name").as_string()))
        sprite = ResourceManager::GetInstance()->GetSprite(GetXMLData(node, "Sprite name").as_string());
    
    animationRect = sf::Rect<int>(GetXMLData(node, "Rectangle X").as_int(), GetXMLData(node, "Rectangle Y").as_int(), GetXMLData(node, "Rectangle Width").as_int(), GetXMLData(node, "Rectangle Height").as_int());
}