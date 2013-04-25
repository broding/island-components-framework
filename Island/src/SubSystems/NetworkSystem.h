//
//  NetworkSystem.h
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__NetworkSystem__
#define __Island__NetworkSystem__

#include <iostream>

#include "SubSystem.h"

class NetworkSystem : public SubSystem
{
public:
    NetworkSystem();
    ~NetworkSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__NetworkSystem__) */
