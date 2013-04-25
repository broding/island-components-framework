//
//  HealthSystem.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "HealthSystem.h"
#include "HealthComponent.h"
#include <math.h>

void HealthSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        HealthComponent* component = static_cast<HealthComponent*>(*iterator);
        
        if(component->health <= 0)
            // do death event
            
        component->health += component->regenRate * lastFrameTime;
        component->health = std::min(component->health, component->maxHealth);
    }
}