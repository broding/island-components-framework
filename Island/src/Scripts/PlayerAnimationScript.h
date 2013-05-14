//
//  PlayerAnimationScript.h
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_PlayerAnimationScript_h
#define Island_PlayerAnimationScript_h

#include <iostream>
#include "BaseScript.h"
#include "Entity.h"
#include "PhysicsComponent.h"

class PlayerAnimationScript : public BaseScript
{
public:
    void RunScript(Entity* entity, float lastFrameTime)
    {
        PhysicsComponent* physics = entity->GetComponent<PhysicsComponent>();
        RenderComponent* render = entity->GetComponent<RenderComponent>();
        
        if(physics != 0 && render != 0)
        {
            if(physics->velocity.x != 0 || physics->velocity.y != 0)
                render->SetAnimation("walk");
            else
                render->SetAnimation("idle");
        }
    }
};

#endif
