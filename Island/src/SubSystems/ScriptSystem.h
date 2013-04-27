//
//  ScriptSystem.h
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ScriptSystem__
#define __Island__ScriptSystem__

#include <iostream>
#include "SubSystem.h"

class ScriptSystem : public SubSystem
{
public:
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
private:
    virtual void ProcessEvent(Component* component, Event* event);
};

#endif /* defined(__Island__ScriptSystem__) */
