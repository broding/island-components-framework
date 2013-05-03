//
//  WeaponComponent.cpp
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "WeaponComponent.h"
#include "WeaponSystem.h"

WeaponSystem* WeaponComponent::weaponSystem;

WeaponComponent::WeaponComponent()
{
    _type = COMPONENT_WEAPON;
    _subSystem = weaponSystem;
    
    this->AddToSystem();
    
    currentMagazine = 10;
    magazineSize = 10;
    
    rateOfFire = 0.1f;
    timeToReload = 1.1f;
    
    isReloading = false;
    isFiring = false;
    
    reloadTime = 0.0f;
    fireTime = 0.0f;
}



pugi::xml_node WeaponComponent::CreateXML()
{
    pugi::xml_node dataNode;
    
    pugi::xml_node node;
    node.set_name("component");
    node.append_attribute("type").set_value("transform");
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    return node;
}

void WeaponComponent::UpdateFromXML(pugi::xml_node node)
{
    
}