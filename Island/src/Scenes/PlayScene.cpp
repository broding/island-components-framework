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
#include "CameraComponent.h"

PlayScene::PlayScene()
{
    AddEntity(CommonFactory::CreateSprite("icon.png"));
    
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