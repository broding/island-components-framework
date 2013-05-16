//
//  BaseScript.h
//  Island
//
//  Created by Bas Roding on 28-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__BaseScript__
#define __Island__BaseScript__

#include <iostream>
#include "Entity.h"

class BaseScript
{
public:
    virtual ~BaseScript() {};
    virtual void RunScript(Entity* entity, float lastFrameTime) = 0;
};

#endif /* defined(__Island__BaseScript__) */
