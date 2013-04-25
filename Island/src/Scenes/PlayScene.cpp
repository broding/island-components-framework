//
//  PlayScene.cpp
//  Island
//
//  Created by Bas Roding on 28-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "PlayScene.h"
#include "PlayerFactory.h"
#include "CommonFactory.h"
#include "StructureFactory.h"
#include "CameraComponent.h"

PlayScene::PlayScene()
{
    AddEntity(StructureFactory::CreateWall(sf::Vector2f(300, 300), 0, 200, 40));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(50, -50), 32));
    
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(250, -520), 32));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(550, 250), 32));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(90, -50), 16));
    
    Entity* camera = CommonFactory::CreateCamera();
    Entity* player = PlayerFactory::CreatePlayer();
    
    camera->GetComponent<CameraComponent>()->targetEntity = player;
    
    AddEntity(camera);
    AddEntity(player);
}

PlayScene::~PlayScene()
{
    
}

void PlayScene::ProcessGUIEvent(GUIEvent event)
{
    
}