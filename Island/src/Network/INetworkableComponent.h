//
//  INetworkableComponent.h
//  Island
//
//  Created by Bas Roding on 26-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_INetworkableComponent_h
#define Island_INetworkableComponent_h

class INetworkableComponent
{
public:
    virtual ~INetworkableComponent() {}
    virtual const void* GenerateNetworkPacket() = 0;
    virtual void ApplyNetworkPacket() = 0;
};

#endif
