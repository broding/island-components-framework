//
//  Core.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Core.h"

#include "RenderSystem.h"
#include "TransformSystem.h"
#include "PhysicsSystem.h"
#include "PlayerInputSystem.h"
#include "NetworkSystem.h"
#include "CameraSystem.h"

#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "NetworkComponent.h"
#include "CameraComponent.h"

#include "ConnectScene.h"

#include "Entity.h"
#include "ResourcePath.hpp"

Core::Core(sf::RenderWindow* window) : _renderWindow(window)
{
    GUIObject::window = window;
    
    InitializeSubSystems();
    SwitchScene(new ConnectScene());
}

Core::~Core()
{
    for (std::vector<SubSystem*>::const_iterator it = _subSystems.begin(), end = _subSystems.end(); it != end; ++it)
        delete *it;
}

void Core::InitializeSubSystems()
{
    RenderSystem* renderSystem = new RenderSystem(_renderWindow);
    TransformSystem* transformSystem = new TransformSystem();
    PhysicsSystem* physicsSystem = new PhysicsSystem();
    PlayerInputSystem* playerInputSystem = new PlayerInputSystem(_renderWindow);
    NetworkSystem* networkSystem = new NetworkSystem();
    CameraSystem* cameraSystem = new CameraSystem(_renderWindow);
    
    AddSubSystem(cameraSystem);
    AddSubSystem(playerInputSystem);
    AddSubSystem(physicsSystem);
    AddSubSystem(transformSystem);
    AddSubSystem(renderSystem);
    AddSubSystem(networkSystem);
    
    // setup subsystems in components
    RenderComponent::renderSystem = renderSystem;
    TransformComponent::transformSystem = transformSystem;
    PhysicsComponent::physicsSystem = physicsSystem;
    PlayerInputComponent::playerInputSystem = playerInputSystem;
    NetworkComponent::networkSystem = networkSystem;
    CameraComponent::cameraSystem = cameraSystem;
}

void Core::AddSubSystem(SubSystem *subSystem)
{
    _subSystems.push_back(subSystem);
}

void Core::Update(float lastFrameTime)
{
    for (std::vector<SubSystem*>::const_iterator iterator = _subSystems.begin(), end = _subSystems.end(); iterator != end; ++iterator)
    {
        (*iterator)->ProcessGameTick(lastFrameTime, (*iterator)->GetValidComponents());
    }
    
    if(_currentScene != 0)
    {
        _currentScene->Update(lastFrameTime);
        _currentScene->Draw(_renderWindow);
    }
}

void Core::SwitchScene(Scene* scene)
{
    //delete _currentScene
    
    _currentScene = scene;
    _currentScene->SetCore(this);
}