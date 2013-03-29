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

PlayScene::PlayScene()
{
    AddEntity(CommonFactory::CreateSprite("icon.png"));
    AddEntity(PlayerFactory::CreatePlayer());
}

PlayScene::~PlayScene()
{
    
}

void PlayScene::ProcessGUIEvent(GUIEvent event)
{
    
}