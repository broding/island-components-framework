//
//  Scene.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Scene.h"

void Scene::AddGUIObject(IGUIObject *object)
{
    this->guiObjects.push_back(object);
}
