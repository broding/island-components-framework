//
//  WeaponEvents.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_WeaponEvents_h
#define Island_WeaponEvents_h

#include "Event.h"
#include "WeaponComponent.h"
#include <SFML/System.hpp>

struct ShootEvent : public Event
{
public:
    sf::Vector2f position;
    WeaponComponent* weaponComponent;
    
    ShootEvent(sf::Vector2f position, WeaponComponent* weaponComponent) : position(position), weaponComponent(weaponComponent)
    {
        type = EVENT_PLAYERINPUT_SHOOT;
    }
};

#endif
