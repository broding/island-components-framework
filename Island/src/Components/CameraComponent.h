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
#include "CameraSystem.h"
#include "INetworkableComponent.h"

class CameraComponent : public Component
{
private:
public:
    CameraComponent();
    
    static CameraSystem* cameraSystem;
    
    sf::Vector2f position;
    sf::Vector2f halfSize;
};

#endif /* defined(__Island__CameraComponent__) */
