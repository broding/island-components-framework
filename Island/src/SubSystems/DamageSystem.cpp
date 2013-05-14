//
//  DamageSystem.cpp
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "DamageSystem.h"
#include "DamageComponent.h"
#include "HealthComponent.h"
#include "Entity.h"

DamageSystem::DamageSystem()
{
    SubscribeToEvent(EVENT_COLLISION);
}

void DamageSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        DamageComponent* component = static_cast<DamageComponent*>(*iterator);
    }
}

void DamageSystem::ProcessEvent(Component *component, Event* event)
{
    switch (event->type) {
        case EVENT_COLLISION:
            HandleCollisionEvent(static_cast<CollisionEvent*>(event), static_cast<DamageComponent*>(component));
            break;
            
        default:
            break;
    }
}

void DamageSystem::HandleCollisionEvent(CollisionEvent *event, DamageComponent *component)
{
    HealthComponent* health = event->other->GetComponent<HealthComponent>();
    
    if(health == 0)
        return;
    
    health->health -= 5;
    
    if(component->deleteOnImpact)
        component->GetOwner()->RemoveComponent(COMPONENT_DAMAGE);
}
