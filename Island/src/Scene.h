//
//  Scene.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Scene__
#define __Island__Scene__

#include <iostream>
#include <vector>
#include "GUIObject.h"
#include <SFML/Graphics.hpp>

class Scene
{
private:
    std::vector<GUIObject*> _guiObjects;
public:
    Scene();
    ~Scene();
    void AddGUIObject(GUIObject* object);
    void RemoveGUIObject(GUIObject* object);
    void Draw(sf::RenderWindow* window);
    void Update(float lastFrameTime);
};
    
#endif /* defined(__Island__Scene__) */
