//
//  ScriptSystem.cpp
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ScriptSystem.h"
#include "ScriptComponent.h"

void ScriptSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    for (std::list<Component*>::const_iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator)
    {
        ScriptComponent* component = static_cast<ScriptComponent*>(*iterator);
        
        if(component->script != 0)
            component->script->RunScript(component->GetOwner(), lastFrameTime);
    }
}

void ScriptSystem::ProcessEvent(Component *component, Event* event)
{
}

