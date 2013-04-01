//
//  CommonFactory.h
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__CommonFactory__
#define __Island__CommonFactory__

#include <iostream>
#include "Entity.h"

class CommonFactory
{
public:
    static Entity* CreateSprite(std::string path);
    static Entity* CreateCamera();
};

#endif /* defined(__Island__CommonFactory__) */
