//
//  DebugText.cpp
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "DebugText.h"
#include "GameConfig.h"
#include "ResourcePath.hpp"

bool DebugText::_isInitialized = false;
DebugText* DebugText::_instance = NULL;

DebugText* DebugText::GetInstance()
{
    if(!_isInitialized)
    {
        _instance = new DebugText();
        _isInitialized = true;
    }
    
    return _instance;
}

void DebugText::Update(float delta)
{
    AddText("FPS", 1 / delta);
}

void DebugText::Draw(sf::RenderWindow *window)
{
    if(!GameConfig::GetInstance()->GetFlagConfig("debugMode"))
        return;
    
    sf::Font myFont;
    if (myFont.loadFromFile(resourcePath() + "Arial.ttf"))
    {
        sf::Text text;
        text.setFont(myFont);
        text.setCharacterSize(12);
        text.setString(_ss.str());
        window->draw(text);
    }
    
    _ss.str("");
}

void DebugText::AddText(std::string name, float value)
{
    if(!GameConfig::GetInstance()->GetFlagConfig("debugMode"))
        return;
    
    _ss << name;
    _ss << ": ";
    _ss << value;
    _ss << std::endl;
}
