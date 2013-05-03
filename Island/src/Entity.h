//
//  Entity.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Entity__
#define __Island__Entity__

#include <iostream>
#include <list>
#include "ComponentType.h"
#include "Event.h"
#include "Component.h"

class Scene;

class Entity
{
    friend class Scene;
private:
    static unsigned int _idIncrementer;
    void SetParent(Scene* scene);
    
    std::string _name;
    std::list<Component*> _components;
    Scene* _scene;
public:
    unsigned int _id;
    Entity(std::string name = "");
    ~Entity();
    
    Scene* GetParent();
    bool IsAddedToScene();
    void InitializeComponents();
    void Delete();
    void AddComponent(Component* component);
    void RemoveComponent(ComponentType type);
    void HandleEvent(Event* event);
    Component* GetComponent(ComponentType type);
    template <class T> T* GetComponent()
    {
        for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
        {
            T* component = dynamic_cast<T*>(*iterator);
            if(component)
                return component;
        }
        
        return NULL;
    }
    
    bool enabled;
};

#endif /* defined(__Island__Entity__) */
