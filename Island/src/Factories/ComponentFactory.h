//
//  ComponentFactory.h
//  Island
//
//  Created by Bas Roding on 16-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ComponentFactory__
#define __Island__ComponentFactory__

#include <iostream>
#include "Component.h"

class ComponentFactory
{
public:
    static Component* CreateComponent(pugi::xml_node xml);
};

#endif /* defined(__Island__ComponentFactory__) */
