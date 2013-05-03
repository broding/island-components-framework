//
//  Scene.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Scene__
#define __Island__Scene__

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "GUIObject.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"

// forward declare Core
class Core;

class Scene : public GUIObserver
{
private:
    std::vector<GUIObject*> _guiObjects;
    Core* _core;
    bool _deleteFlag;
    std::vector<Entity*> _deletedEntities;
    
protected:
    void SwitchScene(Scene* scene);
    
    std::vector<Entity*> _entities;
public:
    Scene();
    virtual ~Scene();
    void AddGUIObject(GUIObject* object);
    void RemoveGUIObject(GUIObject* object);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    void Draw(sf::RenderWindow* window);
    void Update(float lastFrameTime);
    virtual void ProcessGUIEvent(GUIEvent event) = 0;
    void SetCore(Core* core);
    void Delete();
};
    
#endif /* defined(__Island__Scene__) */
