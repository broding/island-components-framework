//
//  ConnectScene.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ConnectScene__
#define __Island__ConnectScene__

#include <iostream>
#include "Scene.h"
#include "Button.h"

class ConnectScene : public Scene
{
private:
    Button makeServerButton;
public:
    ConnectScene();
    ~ConnectScene();
    virtual void ProcessGUIEvent(GUIEvent event);
};

#endif /* defined(__Island__ConnectScene__) */
