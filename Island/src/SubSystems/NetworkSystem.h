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
#include <enet/enet.h>

#include "SubSystem.h"

class NetworkSystem : public SubSystem
{
private:
    ENetHost* host;
    void ProcessEvent(Component* component, Event* event);
public:
    NetworkSystem();
    ~NetworkSystem();
    void ProcessGameTick(float lastFrameTime);
};

#endif /* defined(__Island__NetworkSystem__) */
