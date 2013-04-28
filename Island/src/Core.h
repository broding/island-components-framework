//
//  Core.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Core__
#define __Island__Core__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SubSystem.h"
#include "Scene.h"

class Core
{
private:
    std::vector<SubSystem*> _subSystems;
    Scene* _currentScene;
    sf::RenderWindow* _renderWindow;
    
    void InitializeSubSystems();
    void AddSubSystem(SubSystem* system);
    void DrawDebug();
    
public:
    Core(sf::RenderWindow* window);
    ~Core();
    void Update(float lastFrameTime);
    void SwitchScene(Scene* scene);
};

#endif /* defined(__Island__Core__) */
