//
//  PlayScene.h
//  Island
//
//  Created by Bas Roding on 28-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PlayScene__
#define __Island__PlayScene__

#include "Scene.h"

class PlayScene : public Scene
{
private:
public:
    PlayScene();
    ~PlayScene();
    virtual void ProcessGUIEvent(GUIEvent event);
};

#endif /* defined(__Island__PlayScene__) */
