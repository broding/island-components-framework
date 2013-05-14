//
//  DamageComponent.h
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__DamageComponent__
#define __Island__DamageComponent__

#include <iostream>
#include "Component.h"
#include "DamageSystem.h"

class DamageComponent : public Component
{
public:
    DamageComponent();
    void FillXML(pugi::xml_node &node);
    void UpdateFromXML(pugi::xml_node node);
    
    static DamageSystem* damageSystem;
    
    bool deleteOnImpact;
};


#endif /* defined(__Island__DamageComponent__) */
