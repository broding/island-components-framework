//
//  DamageComponent.cpp
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "DamageComponent.h"

DamageSystem* DamageComponent::damageSystem;

DamageComponent::DamageComponent()
{
    _type = COMPONENT_DAMAGE;
    _subSystem = damageSystem;
    
    this->AddToSystem();
    
    deleteOnImpact = true;
}

void DamageComponent::FillXML(pugi::xml_node &node)
{
    AppendDataNode(node, "Sprite name", "name of sprite in resourcemanager");
}

void DamageComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
