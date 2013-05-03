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
#include <vector>
#include "Component.h"
#include "NetworkSystem.h"
#include "INetworkableComponent.h"

class NetworkComponent : public Component
{
private:
public:
    NetworkComponent();
    pugi::xml_node CreateXML();
    void UpdateFromXML(pugi::xml_node node);
    
    static NetworkSystem* networkSystem;
    
    std::vector<INetworkableComponent*> networkableComponents;
};

#endif /* defined(__Island__NetworkComponent__) */
