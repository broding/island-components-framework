//
//  CameraComponent.h
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__CameraComponent__
#define __Island__CameraComponent__

#include <vector>
#include "Component.h"
#include "INetworkableComponent.h"
#include "CameraSystem.h"

class CameraComponent : public Component
{
private:
public:
    CameraComponent();
    pugi::xml_node CreateXML();
    void UpdateFromXML(pugi::xml_node node);
    
    static CameraSystem* cameraSystem;
    
    void UseCamera();
    
    Entity* targetEntity;
    float maxTargetDistance;
    float snapSpeed;
    
    sf::Vector2f halfSize;
};

#endif /* defined(__Island__CameraComponent__) */
