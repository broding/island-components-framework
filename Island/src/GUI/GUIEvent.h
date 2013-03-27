//
//  GUIEvent.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__GUIEvent__
#define __Island__GUIEvent__

#include <iostream>

class GUIEvent
{
public:
    enum GUIEventType
    {
        BUTTON_HOVERED,
        BUTTON_CLICKED
    };
    
    GUIEvent(unsigned int objectId, GUIEventType type);
    ~GUIEvent();
    unsigned int GetObjectId();
    GUIEventType GetType();
    
private:
    unsigned int _objectId;
    GUIEventType _type;
};

#endif /* defined(__Island__GUIEvent__) */
