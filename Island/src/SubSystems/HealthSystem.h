//
//  HealthSystem.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__HealthSystem__
#define __Island__HealthSystem__

#include <iostream>
#include "SubSystem.h"

class HealthSystem : public SubSystem
{
public:
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__HealthSystem__) */
