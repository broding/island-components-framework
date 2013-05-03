//
//  GameSettings.cpp
//  Island
//
//  Created by Bas Roding on 28-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "GameConfig.h"
#include <string>

bool GameConfig::_isInitialized = false;
GameConfig* GameConfig::_instance = NULL;

GameConfig* GameConfig::GetInstance()
{
    if(!_isInitialized)
    {
        _instance = new GameConfig();
        _isInitialized = true;
    }
    
    return _instance;
}

GameConfig::GameConfig()
{
    _flagConfig.insert(std::pair<std::string,bool>("debugMode",true));
    _flagConfig.insert(std::pair<std::string,bool>("editorMode",false));
}

float GameConfig::GetNumberConfig(std::string config)
{
    return _numberConfig[config];
}

bool GameConfig::GetFlagConfig(std::string config)
{
    return _flagConfig[config];
}

void GameConfig::SetFlagConfig(std::string config, bool flag)
{
    _flagConfig[config] = flag;
}
