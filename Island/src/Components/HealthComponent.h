//
//  HealthComponent.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__HealthComponent__
#define __Island__HealthComponent__

#include <iostream>
#include "Component.h"
#include "HealthSystem.h"

class HealthComponent : public Component
{
private:
public:
    HealthComponent();
    pugi::xml_node CreateXML(pugi::xml_node &node);
    void UpdateFromXML(pugi::xml_node node);
    
    static HealthSystem* healthSystem;
    
    int health;
    int maxHealth;
    int regenRate;
};

#endif /* defined(__Island__HealthComponent__) */
