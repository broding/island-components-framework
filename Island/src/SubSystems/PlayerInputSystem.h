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

class PlayerInputSystem : public SubSystem
{
protected:
    void ProcessEvent(Component* component, Event* event);
public:
    void ProcessGameTick(float lastFrameTime);
};

#endif /* defined(__Island__PlayerInputSystem__) */
