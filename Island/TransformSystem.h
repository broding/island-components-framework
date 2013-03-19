//
//  TransformSystem.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__TransformSystem__
#define __Island__TransformSystem__

#include <iostream>
#include "SubSystem.h"
#include "Event.h"

class TransformSystem : public SubSystem
{
protected:
    void ProcessEvent(Component* component, Event* event);
public:
    void ProcessGameTick(double lastFrameTime);
};

#endif /* defined(__Island__TransformSystem__) */
