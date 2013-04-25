//
//  PlayerInputSystem.h
//  Island
//
//  Created by Bas Roding on 20-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PlayerInputSystem__
#define __Island__PlayerInputSystem__

#include <iostream>
#include "SubSystem.h"
#include <SFML/Graphics.hpp>

class PlayerInputSystem : public SubSystem
{
private:
    sf::RenderWindow* _window;
public:
    PlayerInputSystem(sf::RenderWindow* window);
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__PlayerInputSystem__) */
