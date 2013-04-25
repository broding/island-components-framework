//
//  HealthComponent.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "HealthComponent.h"

HealthSystem* HealthComponent::healthSystem;


HealthComponent::HealthComponent()
{
    _type = COMPONENT_HEALTH;
    _subSystem = healthSystem;
    
    this->AddToSystem();
    
    health = 100;
    maxHealth = 100;
    regenRate = 0;
}


