//
//  WeaponSystem.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "WeaponSystem.h"
#include "WeaponComponent.h"
#include "WeaponEvents.h"

WeaponSystem::WeaponSystem()
{
    SubscribeToEvent(EVENT_PLAYERINPUT_SHOOT);
}

void WeaponSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        WeaponComponent* component = static_cast<WeaponComponent*>(*iterator);
        
        if(component->isFiring)
        {
            if(component->fireTime > component->rateOfFire)
            {
                component->isFiring = false;
                component->fireTime = 0;
            }
            else
            {
                component->fireTime += lastFrameTime;
            }
        }
        
        if(component->isReloading)
        {
            if(component->reloadTime > component->timeToReload)
            {
                component->isReloading = false;
                component->reloadTime = 0;
                component->currentMagazine = component->magazineSize;
            }
            else
            {
                component->reloadTime += lastFrameTime;
            }
        }
    }
}

void WeaponSystem::ProcessEvent(Component *component, Event* event)
{
    switch(event->type)
    {
        case EVENT_PLAYERINPUT_SHOOT:
        {
            ShootEvent* shootEvent = event->GetEvent<ShootEvent>();
            if(shootEvent != NULL)
                Shoot(shootEvent->weaponComponent, shootEvent->position);
        }
        break;
            
        default:
        {
            return;
        }
    }
}

void WeaponSystem::Shoot(WeaponComponent* component, sf::Vector2f position)
{
    if(!component->isReloading && !component->isFiring)
    {
        if(component->currentMagazine > 0)
        {
            component->isFiring = true;
            component->currentMagazine--;
            // fire this damn thing
        }
        else
        {
            component->isReloading = true;
        }
    }
}