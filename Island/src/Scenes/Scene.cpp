//
//  Scene.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Scene.h"
#include "Core.h"

Scene::~Scene()
{
    for (std::vector<GUIObject*>::iterator it = _guiObjects.begin() ; it != _guiObjects.end(); ++it)
        delete *it;
}

void Scene::AddGUIObject(GUIObject *object)
{
    this->_guiObjects.push_back(object);
}

void Scene::RemoveGUIObject(GUIObject *object)
{
    for (std::vector<GUIObject*>::iterator it = _guiObjects.begin() ; it != _guiObjects.end(); ++it)
        if((*it) == object)
        {
            _guiObjects.erase(it);
            break;
        }
}

void Scene::Update(float lastFrameTime)
{
    for (std::vector<GUIObject*>::iterator it = _guiObjects.begin() ; it != _guiObjects.end(); ++it)
        (*it)->Update(lastFrameTime);
}

void Scene::Draw(sf::RenderWindow* window)
{
    for (std::vector<GUIObject*>::iterator it = _guiObjects.begin() ; it != _guiObjects.end(); ++it)
        (*it)->Draw(window);
}

void Scene::SetCore(Core *core)
{
    _core = core;
}

void Scene::SwitchScene(Scene* scene)
{
    _core->SwitchScene(scene);
}
