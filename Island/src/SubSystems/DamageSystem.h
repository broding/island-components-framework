//
//  DamageSystem.h
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__DamageSystem__
#define __Island__DamageSystem__

#include <iostream>
#include "SubSystem.h"
#include "CollisionEvents.h"

// forward decleration
class DamageComponent;

class DamageSystem : public SubSystem
{
public:
    DamageSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
private:
    virtual void ProcessEvent(Component* component, Event* event);
    void HandleCollisionEvent(CollisionEvent* event, DamageComponent* component);
};

#endif /* defined(__Island__DamageSystem__) */
