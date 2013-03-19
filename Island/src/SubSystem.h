//
//  SubSystem.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__SubSystem__
#define __Island__SubSystem__

#include <iostream>
#include <vector>
#include <list>

#include "Event.h"

// forward declare Component
class Component;

class SubSystem
{
private:
protected:
    std::list<Component*> _components;
    std::list<EventType> _subscribedEvents;
    virtual void ProcessEvent(Component* component, Event* event) = 0;
public:
    virtual void ProcessGameTick(double lastFrameTime) = 0;
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    void HandleEvent(Component* component, Event* event);
};

#endif /* defined(__Island__SubSystem__) */
