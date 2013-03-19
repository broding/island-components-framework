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

class Core
{
private:
    std::vector<SubSystem*> _subSystems;
public:
    Core(sf::RenderWindow* window);
    ~Core();
    void Update(float lastFrameTime);
    void AddSubSystem(SubSystem* system);
};

#endif /* defined(__Island__Core__) */
