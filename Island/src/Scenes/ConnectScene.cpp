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
    AddGUIObject(button);
}

ConnectScene::~ConnectScene()
{
    
}
