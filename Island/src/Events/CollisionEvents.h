//
//  CollisionEvents.h
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_CollisionEvents_h
#define Island_CollisionEvents_h

#include "Event.h"
#include "Entity.h"

struct CollisionEvent : public Event
{
public:
    Entity* other;
    
    CollisionEvent(Entity* other) : other(other)
    {
        type = EVENT_COLLISION;
    }
};

#endif
