//
//  RenderComponent.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__RenderComponent__
#define __Island__RenderComponent__

#include <iostream>
#include "Component.h"
#include "RenderSystem.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Sprite.h"


struct AnimationFrame
{
    int index;
    float time;
    
    AnimationFrame(int index, float time) : index(index), time(time)
    {
    }
};


struct Animation
{
    std::vector<AnimationFrame> frames;
    std::string name;
    unsigned int currentFrame;
    float currentFrameTime;
    bool looping;
    
    Animation(std::string name) : name(name), looping(true), currentFrame(0), currentFrameTime(0)
    {
    }
};

class RenderComponent : public Component
{
private:
public:
    RenderComponent();
    ~RenderComponent();
    void SetAnimation(std::string name);
    void FillXML(pugi::xml_node &node);
    void UpdateFromXML(pugi::xml_node node);
    
    static RenderSystem* renderSystem;
    
    Sprite sprite;
    sf::Rect<int> animationRect;
    sf::Vector2<unsigned int> tiling;
    
    std::vector<Animation> animations;
    Animation* currentAnimation;
};

#endif /* defined(__Island__RenderComponent__) */
