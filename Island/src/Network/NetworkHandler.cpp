//
//  NetworkHandler.cpp
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "NetworkHandler.h"

NetworkHandler::NetworkHandler()
{
    if(enet_initialize() != 0)
    {
        // error occured
    }
}

NetworkHandler::~NetworkHandler()
{
    enet_deinitialize();
    enet_host_destroy(host);
}

void NetworkHandler::InitializeServer()
{
    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    
    host = enet_host_create(&address, 32, 2, 57600 /8, 14400 / 8);
}

void NetworkHandler::Connect(std::string ipAdress)
{
    host = enet_host_create(NULL, 1, 2, 57600 /8, 14400 / 8);
}