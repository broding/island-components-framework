//
//  NetworkHandler.h
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__NetworkHandler__
#define __Island__NetworkHandler__

#include <iostream>
#include <enet/enet.h>

class NetworkHandler
{
private:
    ENetHost* host;
public:
    NetworkHandler();
    ~NetworkHandler();
    void InitializeServer();
    void Connect(std::string ipAdress);
};

#endif /* defined(__Island__NetworkHandler__) */
