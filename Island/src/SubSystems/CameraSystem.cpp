//
//  CameraSystem.cpp
//  Island
//
//  Created by Bas Roding on 29-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "CameraSystem.h"
#include "CameraComponent.h"
#include <SFML/System.hpp>
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "Entity.h"
#include "VectorUtil.h"
#include "CommonUtil.h"

CameraSystem::CameraSystem(sf::RenderWindow* window) : _window(window)
{
    currentCamera = NULL;
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::ProcessGameTick(float lastFrameTime, std::list<Component*> components)
{
    if(currentCamera != NULL)
    {
        TransformComponent* cameraTransform = currentCamera->GetOwner()->GetComponent<TransformComponent>();
        
        if(currentCamera->targetEntity != NULL)
        {
            TransformComponent* targetTransform = currentCamera->targetEntity->GetComponent<TransformComponent>();
            PhysicsComponent* cameraPhysics = currentCamera->GetOwner()->GetComponent<PhysicsComponent>();
            
            sf::Vector2f delta = targetTransform->position - cameraTransform->position;
            float distance = VectorUtil::MagnitudeSquared(delta);
            
            if(distance > currentCamera->maxTargetDistance * currentCamera->maxTargetDistance)
                cameraPhysics->velocity = VectorUtil::Normalized(delta) * (distance / currentCamera->maxTargetDistance) * currentCamera->snapSpeed;
            else
                cameraPhysics->velocity *= 0.8f;
        }
        
        sf::View view(cameraTransform->position, currentCamera->halfSize);
        
        _window->setView(view);
    }
}

void CameraSystem::ProcessEvent(Component *component, Event* event)
{
    delete event;
}