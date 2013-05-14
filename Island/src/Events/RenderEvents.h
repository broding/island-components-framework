//
//  RenderEvents.h
//  Island
//
//  Created by Bas Roding on 14-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_RenderEvents_h
#define Island_RenderEvents_h

#include "Event.h"

struct PlayAnimationEvent : public Event
{
public:
    std::string name
    
    ShootEvent(std::string name) : name(name)
    {
        type = EVENT_PLAY_ANIMATION;
    }
};

#endif
