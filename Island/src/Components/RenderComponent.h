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

class RenderComponent : public Component
{
private:
public:
    RenderComponent();
    ~RenderComponent();
    
    static RenderSystem* renderSystem;
    
    sf::Sprite sprite;
};

#endif /* defined(__Island__RenderComponent__) */
