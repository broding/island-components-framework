//
//  ScriptComponent.h
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ScriptComponent__
#define __Island__ScriptComponent__

#include <iostream>
#include "Component.h"
#include "ScriptSystem.h"
#include "BaseScript.h"

class ScriptComponent : public Component
{
public:
    ScriptComponent();
    ~ScriptComponent();
    
    static ScriptSystem* scriptSystem;
    
    BaseScript* script;
};

#endif /* defined(__Island__ScriptComponent__) */
