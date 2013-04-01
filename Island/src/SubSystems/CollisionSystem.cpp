//
//  CollisionSystem.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CollisionSystem.h"
#include "IntersectionTests.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"

void CollisionSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    ContactList contactList;
    
    for (std::list<Component*>::const_iterator it1 = components.begin(), end = components.end(); it1 != end; ++it1)
    {
        for (std::list<Component*>::const_iterator it2 = components.begin(), end = components.end(); it2 != end; ++it2)
        {
            if(it1 == it2)
                continue;
            
            if((*it1)->GetComponentType() == COMPONENT_SPHERECOLLISION && (*it2)->GetComponentType() == COMPONENT_SPHERECOLLISION)
                continue; // sphere to sphere
            else if((*it1)->GetComponentType() == COMPONENT_BOXCOLLISION && (*it2)->GetComponentType() == COMPONENT_SPHERECOLLISION)
                continue;// box to sphere
            else if((*it1)->GetComponentType() == COMPONENT_SPHERECOLLISION && (*it2)->GetComponentType() == COMPONENT_BOXCOLLISION)
                continue;// sphere to box
            else
                IntersectionTests::BoxAndBox(static_cast<BoxCollisionComponent*>(*it1),static_cast<BoxCollisionComponent*>(*it2), contactList);
        }
    }
    
    for (std::vector<Contact>::const_iterator it = contactList.GetContacts().begin(), end = contactList.GetContacts().end(); it != end; ++it)
        Resolve((*it));
    
}

void CollisionSystem::Resolve(Contact contact)
{
    if(!contact.entity1->GetComponent<BoxCollisionComponent>()->trigger && !contact.entity2->GetComponent<BoxCollisionComponent>()->trigger)
    {
        contact.entity1->GetComponent<TransformComponent>()->position = contact.entity1->GetComponent<TransformComponent>()->previousPosition;
        
        contact.entity2->GetComponent<TransformComponent>()->position = contact.entity2->GetComponent<TransformComponent>()->previousPosition;
    }
        
}

void CollisionSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}
