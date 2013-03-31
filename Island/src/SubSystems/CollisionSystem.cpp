//
//  CollisionSystem.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CollisionSystem.h"
#include "Contact.h"
#include "IntersectionTests.h"
#include "BoxCollisionComponent.h"

void CollisionSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    ContactList contactList;
    
    for (std::list<Component*>::const_iterator it1 = components.begin(), end = components.end(); it1 != end; ++it1)
    {
        for (std::list<Component*>::const_iterator it2 = components.begin(), end = components.end(); it2 != end; ++it2)
        {
            if(it1 == it2)
                continue;
            
            IntersectionTests::BoxAndBox(static_cast<BoxCollisionComponent*>(*it1),static_cast<BoxCollisionComponent*>(*it2), contactList);
        }
    }
}

void CollisionSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}
