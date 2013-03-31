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
    AddEntity(StructureFactory::CreateWall(sf::Vector2f(100, 100), 45, 200, 20));
    
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