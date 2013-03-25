//
//  NetworkComponent.h
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__NetworkComponent__
#define __Island__NetworkComponent__

#include <iostream>
#include "Component.h"
#include "NetworkSystem.h"

class NetworkComponent : public Component
{
private:
public:
    NetworkComponent();
    ~NetworkComponent();
    
    static NetworkSystem* networkSystem;
    
};

#endif /* defined(__Island__NetworkComponent__) */
