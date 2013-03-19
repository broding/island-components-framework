//
//  Component.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Component__
#define __Island__Component__

#include <iostream>

// forward declare Entity to prevent circular depandency
class Entity;

class Component
{
private:
public:
    Component();
    ~Component();
    
    virtual void Update(double delta) = 0;
    
    void SetOwner(Entity* entity);
    Entity* GetOwner();
};

#endif /* defined(__Island__Component__) */
