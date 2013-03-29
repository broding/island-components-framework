//
//  PhysicsSystem.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PhysicsSystem__
#define __Island__PhysicsSystem__

#include <iostream>
#include "SubSystem.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"

class PhysicsSystem : public SubSystem
{
private:
    void Integrate(PhysicsComponent* physicsComponent, TransformComponent* transformComponent, float lastFrameTime);
protected:
    void ProcessEvent(Component* component, Event* event);
public:
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__PhysicsSystem__) */
