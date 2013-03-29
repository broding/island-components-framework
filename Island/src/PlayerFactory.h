//
//  PlayerFactory.h
//  Island
//
//  Created by Bas Roding on 28-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PlayerFactory__
#define __Island__PlayerFactory__

#include <iostream>
#include "Entity.h"

class PlayerFactory
{
public:
    static Entity* CreatePlayer();
};

#endif /* defined(__Island__PlayerFactory__) */
