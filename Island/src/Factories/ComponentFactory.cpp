//
//  ComponentFactory.cpp
//  Island
//
//  Created by Bas Roding on 16-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ComponentFactory.h"

#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"
#include "CameraComponent.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "HealthComponent.h"
#include "WeaponComponent.h"
#include "ScriptComponent.h"
#include "DamageComponent.h"

Component* ComponentFactory::CreateComponentByType(ComponentType type)
{
    switch(type)
    {
        case COMPONENT_RENDER:
            return new RenderComponent();
            break;
        case COMPONENT_TRANSFORM:
            return new TransformComponent();
            break;
        case COMPONENT_PHYSICS:
            return new PhysicsComponent();
            break;
        case COMPONENT_PLAYERINPUT:
            return new PlayerInputComponent();
            break;
        case COMPONENT_NETWORK:
            return new NetworkComponent();
            break;
        case COMPONENT_CAMERA:
            return new CameraComponent();
            break;
        case COMPONENT_BOXCOLLISION:
            return new BoxCollisionComponent();
            break;
        case COMPONENT_SPHERECOLLISION:
            return new SphereCollisionComponent();
            break;
        case COMPONENT_HEALTH:
            return new HealthComponent();
            break;
        case COMPONENT_WEAPON:
            return new WeaponComponent();
            break;
        case COMPONENT_SCRIPT:
            return new ScriptComponent();
            break;
        case COMPONENT_DAMAGE:
            return new DamageComponent();
            break;
        case COMPONENT_NULL:
            return 0;
            break;
    }
    
    return 0;
}

Component* ComponentFactory::CreateComponentFromXML(pugi::xml_node xml)
{
    
}