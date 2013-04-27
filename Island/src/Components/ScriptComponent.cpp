//
//  ScriptComponent.cpp
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ScriptComponent.h"

ScriptSystem* ScriptComponent::scriptSystem;

ScriptComponent::ScriptComponent()
{
    _type = COMPONENT_SCRIPT;
    _subSystem = scriptSystem;
    
    this->AddToSystem();
}