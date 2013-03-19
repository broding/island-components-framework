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
#include <map>
#include "Component.h"

class Entity
{
private:
    std::string _name;
    unsigned int _id;
    std::map<std::string, Component*> _components;
public:
    Entity();
    Entity(std::string name);
    ~Entity();
    void AddComponent(Component* component);
    void RemoveComponent(std::string);
    void RemoveComponent(unsigned int);
};

#endif /* defined(__Island__Entity__) */
