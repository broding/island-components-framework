//
//  CameraSystem.h
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__CameraSystem__
#define __Island__CameraSystem__

#include <iostream>

#include "SubSystem.h"
#include <SFML/Graphics.hpp>

class CameraComponent;

class CameraSystem : public SubSystem
{
private:
    sf::RenderWindow* _window;
public:
    CameraSystem(sf::RenderWindow* window);
    ~CameraSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
    
    CameraComponent* currentCamera;
};

#endif /* defined(__Island__CameraSystem__) */
