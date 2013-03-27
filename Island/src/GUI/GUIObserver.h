//
//  GUIObserver.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__GUIObserver__
#define __Island__GUIObserver__

#include "GUIEvent.h"

class GUIObserver
{
public:
    virtual void ProcessGUIEvent(GUIEvent event) = 0;
};

#endif /* defined(__Island__GUIObserver__) */
