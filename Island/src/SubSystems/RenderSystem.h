//
//  RenderSystem.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__RenderSystem__
#define __Island__RenderSystem__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SubSystem.h"

// forward declares
class RenderComponent;

class RenderSystem : public SubSystem
{
private:
    sf::RenderWindow* _renderWindow;
protected:
public:
    RenderSystem(sf::RenderWindow* renderWindow);
    ~RenderSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__RenderSystem__) */
