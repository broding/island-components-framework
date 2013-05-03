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

class WeaponSystem;

class WeaponComponent : public Component
{
public:
    WeaponComponent();
    pugi::xml_node CreateXML();
    void UpdateFromXML(pugi::xml_node node);
    
    static WeaponSystem* weaponSystem;
    
    float currentMagazine;
    float magazineSize;
    
    float rateOfFire;
    float timeToReload;
    bool isReloading;
    bool isFiring;
    
    float reloadTime;
    float fireTime;
};

#endif /* defined(__Island__WeaponComponent__) */
