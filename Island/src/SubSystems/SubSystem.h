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
#include <SFML/Graphics.hpp>

// forward declare Component
class Component;

class SubSystem
{
private:
    std::list<Component*> _components;
    bool _subscribedEvents[EVENT_LAST_TYPE];
protected:
    virtual void ProcessEvent(Component* component, Event* event);
    void SubscribeToEvent(EventType type);
    void UnsubscribeToEvent(EventType type);
public:
    virtual ~SubSystem();
    virtual void ProcessGameTick(float lastFrameTime, std::list<Component*> components) = 0;
    std::list<Component*> GetValidComponents();
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    void HandleEvent(Component* component, Event* event);
    virtual void DrawDebug(sf::RenderWindow* window);
};

#endif /* defined(__Island__SubSystem__) */
