//
//  Scene.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Scene.h"
#include "Core.h"
#include "DebugText.h"

Scene::Scene()
{
    _deleteFlag = false;
}

Scene::~Scene()
{
    while(!_guiObjects.empty()) delete _guiObjects.back(), _guiObjects.pop_back();
    while(!_entities.empty()) delete _entities.back(), _entities.pop_back();
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

void Scene::AddEntity(Entity *entity)
{
    this->_entities.push_back(entity);
    entity->SetParent(this);
}

void Scene::RemoveEntity(Entity *entity)
{
    for (std::vector<Entity*>::iterator it = _entities.begin() ; it != _entities.end(); ++it)
        if((*it) == entity)
        {
            _entities.erase(it);
            break;
        }
    
    entity->SetParent(NULL);
}

void Scene::Update(float lastFrameTime)
{
    if(_deleteFlag)
        delete this;
    
    for (std::vector<GUIObject*>::iterator it = _guiObjects.begin() ; it != _guiObjects.end(); ++it)
        (*it)->Update(lastFrameTime);
    
    DebugText::GetInstance()->AddText("Total entities", (float)_entities.size());
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

void Scene::Delete()
{
    _deleteFlag = true;
}
