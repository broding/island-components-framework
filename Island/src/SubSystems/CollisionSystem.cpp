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
                IntersectionTests::SphereAndSphere(static_cast<SphereCollisionComponent*>(*it1),static_cast<SphereCollisionComponent*>(*it2), contactList);
            else if((*it1)->GetComponentType() == COMPONENT_BOXCOLLISION && (*it2)->GetComponentType() == COMPONENT_SPHERECOLLISION)
                IntersectionTests::BoxAndSphere(static_cast<BoxCollisionComponent*>(*it1),static_cast<SphereCollisionComponent*>(*it2), contactList);
            else if((*it1)->GetComponentType() == COMPONENT_SPHERECOLLISION && (*it2)->GetComponentType() == COMPONENT_BOXCOLLISION)
                IntersectionTests::BoxAndSphere(static_cast<BoxCollisionComponent*>(*it2), static_cast<SphereCollisionComponent*>(*it1),contactList);
            else
                IntersectionTests::BoxAndBox(static_cast<BoxCollisionComponent*>(*it1),static_cast<BoxCollisionComponent*>(*it2), contactList);
        }
    }
    
    for (std::vector<Contact>::const_iterator it = contactList.GetContacts().begin(), end = contactList.GetContacts().end(); it != end; ++it)
        Resolve((*it));
    
}

void CollisionSystem::Resolve(Contact contact)
{
    ICollisionComponent* entity1Collision = contact.entity1->GetComponent<ICollisionComponent>();
    ICollisionComponent* entity2Collision = contact.entity2->GetComponent<ICollisionComponent>();
    
    if(!entity1Collision->trigger && !entity2Collision->trigger)
    {
        contact.entity1->GetComponent<TransformComponent>()->position += contact.normal * contact.penetration;
        
        contact.entity2->GetComponent<TransformComponent>()->position -= contact.normal * contact.penetration;
        
        PhysicsComponent* entity1Physics = contact.entity1->GetComponent<PhysicsComponent>();
        PhysicsComponent* entity2Physics = contact.entity2->GetComponent<PhysicsComponent>();
        
        float x1 = VectorUtil::DotProduct(contact.normal, entity1Physics->velocity);
        sf::Vector2f v1x = contact.normal * x1;
        sf::Vector2f v1y = entity1Physics->velocity - v1x;
        
        float x2 = VectorUtil::DotProduct(contact.normal, entity2Physics->velocity);
        sf::Vector2f v2x = contact.normal * x2;
        sf::Vector2f v2y = entity2Physics->velocity - v2x;
        
        float massFormula1 = (entity1Physics->mass - entity2Physics->mass) / (entity1Physics->mass + entity2Physics->mass);
        float massFormula2 = (2 * entity1Physics->mass) / (entity1Physics->mass + entity2Physics->mass);
        
        if(!entity1Collision->solid)
            entity1Physics->velocity = v1x * massFormula1 + v2x * massFormula2 + v1y;
        
        if(!entity2Collision->solid)
             entity2Physics->velocity = v1x * massFormula2 + v2x * massFormula1 + v2y;
    }
}

void CollisionSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}
