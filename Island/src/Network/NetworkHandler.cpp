//
//  NetworkHandler.cpp
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "NetworkHandler.h"

ENetHost* NetworkHandler::host;

void NetworkHandler::InitializeEnet()
{
    if(enet_initialize() != 0)
    {
        // error occured
    }
}

void NetworkHandler::InitializeServer()
{
    InitializeEnet();
    
    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    
    host = enet_host_create(&address, 32, 2, 57600 /8, 14400 / 8);
}

void NetworkHandler::Connect(std::string ipAdress)
{
    InitializeEnet();
    
    host = enet_host_create(NULL, 1, 2, 57600 /8, 14400 / 8);
}

void NetworkHandler::Disconnect()
{
    enet_host_destroy(host);
    enet_deinitialize();
}