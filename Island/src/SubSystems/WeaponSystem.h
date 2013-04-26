//
//  WeaponSystem.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__WeaponSystem__
#define __Island__WeaponSystem__

#include <iostream>
#include "SubSystem.h"
#include "WeaponEvents.h"

class WeaponSystem : public SubSystem
{
public:
    WeaponSystem();
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
private:
    virtual void ProcessEvent(Component* component, Event* event);
    void Shoot(WeaponComponent* component, sf::Vector2f position);
};

#endif /* defined(__Island__WeaponSystem__) */
