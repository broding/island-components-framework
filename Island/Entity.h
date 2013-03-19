//
//  Entity.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Entity__
#define __Island__Entity__

#include <iostream>
#include <list>
#include "ComponentType.h"
#include "Event.h"

// forward declare Component
class Component;

class Entity
{
private:
    std::string _name;
    unsigned int _id;
    std::list<Component*> _components;
public:
    Entity();
    Entity(std::string name);
    ~Entity();
    void AddComponent(Component* component);
    void RemoveComponent(ComponentType type);
    void HandleEvent(Event* event);
};

#endif /* defined(__Island__Entity__) */
