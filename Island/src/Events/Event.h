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
    EVENT_LAST_TYPE = 0
};

struct Event
{
    EventType type;
};



#endif /* defined(__Island__Event__) */
