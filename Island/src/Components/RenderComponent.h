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

struct AnimationFrame
{
    int index;
    float time;
    
    AnimationFrame(int index, float time) : index(index), time(time)
    {
    }
};

class RenderComponent : public Component
{
private:
public:
    RenderComponent();
    ~RenderComponent();
    
    static RenderSystem* renderSystem;
    
    sf::Sprite sprite;
    sf::Rect<int> textureRect;
    sf::Vector2<unsigned int> tiling;
    
    std::vector<AnimationFrame> frames;
    unsigned int currentFrame;
    float currentFrameTime;
    bool looping;
};

#endif /* defined(__Island__RenderComponent__) */
