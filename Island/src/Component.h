//
//  Component.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Component__
#define __Island__Component__

#include <iostream>
#include <map>

#include "Event.h"
#include "SubSystem.h"
#include "ComponentType.h"
#include "Entity.h"

class Component
{
private:
    Entity* _owner;
protected:
    ComponentType _type;
    SubSystem* _subSystem;
    std::map<ComponentType, Component*> _componentSubscriptions;
public:
    Component();
    virtual ~Component();
    
    ComponentType GetComponentType();
    void SetOwner(Entity* entity);
    Entity* GetOwner();
    void HandleEvent(Event* event);
    void AddComponentSubscription(ComponentType type);
    void RemoveComponentSubscription(ComponentType type);
    void AddNeighbourComponent(Component* component);
    void RemoveNeighbourComponent(Component* component);
    
    Component* GetNeighbourComponent(ComponentType type);
};

#endif /* defined(__Island__Component__) */
