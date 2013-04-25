//
//  WeaponComponent.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "WeaponComponent.h"

WeaponSystem* WeaponComponent::weaponSystem;

WeaponComponent::WeaponComponent()
{
    _type = COMPONENT_WEAPON;
    _subSystem = weaponSystem;
    
    this->AddToSystem();
    
    rateOfFire = 0.5f;
    reloadTime = 1.1f;
}