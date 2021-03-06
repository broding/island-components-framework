//
//  IntersectionTests.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_IntersectionTests_h
#define Island_IntersectionTests_h

#include <iostream>
#include "Contact.h"
#include "BoxCollisionComponent.h"
#include "SphereCollisionComponent.h"
#include "TransformComponent.h"
#include "VectorUtil.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Projection.h"
#include "Entity.h"
#include "GUIObject.h"

class IntersectionTests
{
private:
    
    static sf::Vector2f* GetAxisOfShape(const sf::ConvexShape shape, const int additionalRoom = 0)
    {
        sf::Vector2f* axis = new sf::Vector2f[shape.getPointCount() + additionalRoom];
        
        for(unsigned int i = 0; i < shape.getPointCount(); i++)
        {
            sf::Vector2f p1 = shape.getPoint(i);
            sf::Vector2f p2 = shape.getPoint(i + 1 == shape.getPointCount() ? 0 : i + 1);
            sf::Vector2f edge = p2 - p1;
            sf::Vector2f normal = VectorUtil::Perpendicular(VectorUtil::Normalized(edge));
            axis[i] = normal;
        }
        
        return axis;
    }

    static sf::Vector2f ClosestConvexPoint(const sf::Vector2f point, const sf::ConvexShape shape)
    {
        int closestPoint = 0;
        float squaredLength = 9999999;
        
        for(unsigned int i = 0; i < shape.getPointCount(); i++)
        {
            float newLength = VectorUtil::Magnitude(shape.getPoint(i) - point);
            
            if(newLength < squaredLength)
            {
                squaredLength = newLength;
                closestPoint = i;
            }
        }
        
        return shape.getPoint(closestPoint);
    }
    
public:
    
    static Projection ProjectOnAxis(const sf::ConvexShape shape, const sf::Vector2f axis)
    {
        float min = VectorUtil::DotProduct(axis, shape.getPoint(0));
        float max = min;
        
        for(unsigned int i = 1; i < shape.getPointCount(); i++)
        {
            float p = VectorUtil::DotProduct(axis, shape.getPoint(i));
            
            if(p < min)
                min = p;
            else if(p > max)
                max = p;
        }
        
        return Projection(min, max);
    }

    
    static void SphereAndSphere(SphereCollisionComponent* sphere1, SphereCollisionComponent* sphere2, ContactList &contactList)
    {
        if(!sphere1->collisionGroups[sphere2->collisionGroup] && !sphere2->collisionGroups[sphere1->collisionGroup])
            return;
        
        TransformComponent* sphere1Transform = sphere1->GetOwner()->GetComponent<TransformComponent>();
        TransformComponent* sphere2Transform = sphere2->GetOwner()->GetComponent<TransformComponent>();
        float radiusSum = sphere1->radius + sphere2->radius;
        float distance = VectorUtil::Magnitude(sphere1Transform->position - sphere2Transform->position);
        
        if(distance < radiusSum)
        {
            Contact contact;
            contact.penetration = radiusSum - distance;
            contact.normal = VectorUtil::Normalized(sphere1Transform->position - sphere2Transform->position);
            contact.entity1 = sphere1->GetOwner();
            contact.entity2 = sphere2->GetOwner();
            
            contactList.AddContact(contact);
        }
    }
    
    static void BoxAndSphere(BoxCollisionComponent* box, SphereCollisionComponent* sphere, ContactList &contactList)
    {
        if(!sphere->collisionGroups[box->collisionGroup] && !box->collisionGroups[sphere->collisionGroup])
            return;
        
        sf::ConvexShape boxShape = box->GetConvexShape();
        sf::ConvexShape circleShape = sphere->GetConvexShape();
        sf::Vector2f* axis = GetAxisOfShape(boxShape, 1);
        sf::Vector2f circlePosition = sphere->GetOwner()->GetComponent<TransformComponent>()->position;
        sf::Vector2f circleAxis = VectorUtil::Normalized(ClosestConvexPoint(circlePosition, boxShape) - circlePosition);
        axis[boxShape.getPointCount()] = circleAxis;
        
        float penetration = 9999999;
        sf::Vector2f normal;
        
        for(unsigned int i = 0; i < boxShape.getPointCount() + 1; i++)
        {
            sf::Vector2f currentAxis = axis[i];
            
            currentAxis = VectorUtil::Normalized(currentAxis);
            
            Projection p1 = ProjectOnAxis(boxShape, currentAxis);
            Projection p2 = ProjectOnAxis(circleShape, currentAxis);
            
            if(!p1.IsOverlapping(p2))
                return;
            else
            {
                float newPenetration = p1.GetOverlap(p2);
                if(newPenetration < penetration)
                {
                    penetration = newPenetration;
                    normal = currentAxis;
                }
            }
        }
        
        delete axis;
        
        Contact contact;
        contact.penetration = penetration;
        contact.normal = normal;
        contact.entity1 = box->GetOwner();
        contact.entity2 = sphere->GetOwner();
        
        contactList.AddContact(contact);
    }
    
    static void BoxAndBox(BoxCollisionComponent* box1, BoxCollisionComponent* box2, ContactList &contactList)
    {
        if(!box1->collisionGroups[box2->collisionGroup] && !box2->collisionGroups[box1->collisionGroup])
            return;
        
        sf::ConvexShape shape1 = box1->GetConvexShape();
        sf::ConvexShape shape2 = box2->GetConvexShape();
        
        sf::Vector2f* axis1 = GetAxisOfShape(shape1);
        sf::Vector2f* axis2 = GetAxisOfShape(shape2);
        
        float penetration = 9999999;
        sf::Vector2f normal;
        
        for(unsigned int i = 0; i < shape1.getPointCount(); i++)
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
        
        for(unsigned int i = 0; i < shape2.getPointCount(); i++)
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
        
        delete axis1;
        delete axis2;
        
        Contact contact;
        contact.penetration = penetration;
        contact.normal = normal;
        contact.entity1 = box1->GetOwner();
        contact.entity2 = box2->GetOwner();
        
        contactList.AddContact(contact);
    }
};

#endif
