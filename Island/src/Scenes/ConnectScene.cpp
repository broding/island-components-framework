//
//  ConnectScene.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ConnectScene.h"
#include "Button.h"
#include "NetworkHandler.h"
#include "PlayScene.h"

ConnectScene::ConnectScene()
{
    makeServerButton.position = sf::Vector2f(50, 50);
    AddGUIObject(&makeServerButton);
    makeServerButton.RegisterObserver(this);
}

ConnectScene::~ConnectScene()
{
    
}

void ConnectScene::ProcessGUIEvent(GUIEvent event)
{
    if(event.GetObjectId() == makeServerButton.GetId() && event.GetType() == GUIEvent::BUTTON_CLICKED)
    {
        NetworkHandler::InitializeServer();
        SwitchScene(new PlayScene());
    }
}
