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
#include "IGUIObject.h"

class Scene
{
private:
    std::vector<IGUIObject*> guiObjects;
public:
    void AddGUIObject(IGUIObject* object);
};
    
#endif /* defined(__Island__Scene__) */
