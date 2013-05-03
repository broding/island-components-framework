//
//  EditorScene.h
//  Island
//
//  Created by Bas Roding on 03-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__EditorScene__
#define __Island__EditorScene__

#include <iostream>
#include "Scene.h"

class EditorScene : public Scene
{
public:
    EditorScene();
    virtual void ProcessGUIEvent(GUIEvent event);
    const std::vector<Entity*>& GetEntities();
};

#endif /* defined(__Island__EditorScene__) */
