//
//  WeaponSystem.h
//  Island
//
//  Created by Bas Roding on 26-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__WeaponSystem__
#define __Island__WeaponSystem__

#include <iostream>
#include "SubSystem.h"

class WeaponSystem : public SubSystem
{
    void ProcessGameTick(float lastFrameTime, std::list<Component*> components);
};

#endif /* defined(__Island__WeaponSystem__) */
