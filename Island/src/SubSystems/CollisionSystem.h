//
//  CollisionSystem.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__CollisionSystem__
#define __Island__CollisionSystem__

#include <iostream>
#include "SubSystem.h"
#include "Contact.h"

class CollisionSystem : public SubSystem
{
private:
    void ProcessEvent(Component* component, Event* event);
    void Resolve(Contact contact);
public:
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__CollisionSystem__) */
