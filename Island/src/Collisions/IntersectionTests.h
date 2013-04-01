//
//  IntersectionTests.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_IntersectionTests_h
#define Island_IntersectionTests_h

#include "Contact.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "TransformComponent.h"
#include "ConvexShape.h"
#include "VectorUtil.h"
#include <SFML/System.hpp>
#include "Projection.h"
#include "Entity.h"

class IntersectionTests
{
private:
    static sf::Vector2f* GetAxisOfShape(sf::ConvexShape shape)
    {
        sf::Vector2f* axis = new sf::Vector2f[shape.getPointCount()];
        
        for(int i = 0; i < shape.getPointCount(); i++)
        {
            sf::Vector2f p1 = shape.getPoint(i);
            sf::Vector2f p2 = shape.getPoint(i + 1 == shape.getPointCount() ? 0 : i + 1);
            sf::Vector2f edge = p1 - p2;
            sf::Vector2f normal = VectorUtil::Normalized(VectorUtil::Perpendicular(edge));
            axis[i] = normal;
        }
        
        return axis;
    }
    
    static Projection ProjectOnAxis(sf::ConvexShape shape, sf::Vector2f axis)
    {
        float min = VectorUtil::DotProduct(axis, shape.getPoint(0));
        float max = min;
        
        for(int i = 1; i < shape.getPointCount(); i++)
        {
            float p = VectorUtil::DotProduct(axis, shape.getPoint(i));
            
            if(p < min)
                min = p;
            else if(p > max)
                max = p;
        }
        
        return Projection(min, max);
    }
    
public:
    static void SphereAndSphere(SphereCollisionComponent* sphere1, SphereCollisionComponent* sphere2, ContactList &contactList)
    {
        TransformComponent* sphere1Transform = sphere1->GetOwner()->GetComponent<TransformComponent>();
        TransformComponent* sphere2Transform = sphere2->GetOwner()->GetComponent<TransformComponent>();
        float radiusSum = sphere1->radius + sphere2->radius;
        float distance = VectorUtil::Magnitude(sphere1Transform->position - sphere2Transform->position);
        
        if(distance < radiusSum)
        {
            Contact contact;
            contact.penetration = sqrt(radiusSum - distance);
            contact.normal = VectorUtil::Normalized(sphere1Transform->position - sphere2Transform->position);
            contact.entity1 = sphere1->GetOwner();
            contact.entity2 = sphere2->GetOwner();
            
            contactList.AddContact(contact);
        }
    }
    
    static void BoxAndBox(BoxCollisionComponent* box1, BoxCollisionComponent* box2, ContactList &contactList)
    {
        sf::ConvexShape shape1 = box1->GetConvexShape();
        sf::ConvexShape shape2 = box2->GetConvexShape();
        
        sf::Vector2f* axis1 = GetAxisOfShape(shape1);
        sf::Vector2f* axis2 = GetAxisOfShape(shape2);
        
        float penetration = INT_MAX;
        sf::Vector2f normal;
        
        for(int i = 0; i < shape1.getPointCount(); i++)
        {
            sf::Vector2f axis = axis1[i];
            
            Projection p1 = ProjectOnAxis(shape1, axis);
            Projection p2 = ProjectOnAxis(shape2, axis);
            
            if(!p1.IsOverlapping(p2))
                return;
            else
            {
                float newPenetration = p1.GetOverlap(p2);
                if(newPenetration < penetration)
                {
                    penetration = newPenetration;
                    normal = axis;
                }
            }
        }
        
        for(int i = 0; i < shape2.getPointCount(); i++)
        {
            sf::Vector2f axis = axis2[i];
            
            Projection p1 = ProjectOnAxis(shape1, axis);
            Projection p2 = ProjectOnAxis(shape2, axis);
            
            if(!p1.IsOverlapping(p2))
                return;
            else
            {
                float newPenetration = p1.GetOverlap(p2);
                if(newPenetration < penetration)
                {
                    penetration = newPenetration;
                    normal = axis;
                }
            }
        }
        
        Contact contact;
        contact.penetration = penetration;
        contact.normal = normal;
        contact.entity1 = box1->GetOwner();
        contact.entity2 = box2->GetOwner();
        
        contactList.AddContact(contact);
    }
};

#endif
