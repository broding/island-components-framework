//
//  Event.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Event__
#define __Island__Event__

#include <iostream>
#include <SFML/System.hpp>

enum EventType
{
    EVENT_PLAYERINPUT_SHOOT = 0,
    EVENT_PLAY_ANIMATION,
    EVENT_COLLISION,
    EVENT_LAST_TYPE
};

struct Event
{
    virtual ~Event() {};
    
    template <class T> T* GetEvent()
    {
        return dynamic_cast<T*>(this);
    }
    
    EventType type;
};



#endif /* defined(__Island__Event__) */
