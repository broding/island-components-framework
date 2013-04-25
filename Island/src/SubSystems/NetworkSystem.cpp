//
//  NetworkSystem.cpp
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "NetworkSystem.h"

NetworkSystem::NetworkSystem()
{

}

NetworkSystem::~NetworkSystem()
{
}

void NetworkSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
    }
}
