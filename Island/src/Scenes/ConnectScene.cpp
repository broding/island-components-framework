//
//  ConnectScene.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ConnectScene.h"
#include "Button.h"

ConnectScene::ConnectScene()
{
    Button* button = new Button();
    button->position = sf::Vector2f(50, 50);
    AddGUIObject(button);
}

ConnectScene::~ConnectScene()
{
    
}
