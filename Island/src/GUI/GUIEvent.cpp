//
//  GUIEvent.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "GUIEvent.h"

GUIEvent::GUIEvent(unsigned int objectId, GUIEventType type) : _objectId(objectId), _type(type)
{
    
}

GUIEvent::~GUIEvent()
{
}

unsigned int GUIEvent::GetObjectId()
{
    return _objectId;
}

GUIEvent::GUIEventType GUIEvent::GetType()
{
    return _type;
}