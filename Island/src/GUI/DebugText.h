//
//  DebugText.h
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__DebugText__
#define __Island__DebugText__

#include <iostream>
#include "GUIObject.h"
#include <sstream>

class DebugText : public GUIObject
{
public:
    static DebugText* GetInstance();
    
    virtual void Update(float delta);
    virtual void Draw(sf::RenderWindow* window);
    void AddText(std::string name, float value);
private:
    static DebugText* _instance;
    static bool _isInitialized;
    
    std::stringstream _ss;
};

#endif /* defined(__Island__DebugText__) */
