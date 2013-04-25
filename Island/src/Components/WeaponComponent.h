//
//  WeaponComponent.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__WeaponComponent__
#define __Island__WeaponComponent__

#include <iostream>
#include "Component.h"
#include "WeaponSystem.h"

class WeaponComponent : public Component
{
public:
    WeaponComponent();
    
    static WeaponSystem* weaponSystem;
    
    float rateOfFire;
    float reloadTime;
};

#endif /* defined(__Island__WeaponComponent__) */
