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

class CameraSystem : public SubSystem
{
private:
    void ProcessEvent(Component* component, Event* event);
public:
    CameraSystem();
    ~CameraSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__CameraSystem__) */
