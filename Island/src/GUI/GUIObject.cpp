//
//  GUIObject.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "GUIObject.h"

sf::Window* GUIObject::window;

void GUIObject::Select()
{
}

void GUIObject::Click()
{
    
}

sf::Rect<int> GUIObject::GetBoundingBox()
{
    return this->_boundingBox;
}

void GUIObject::Draw(sf::RenderWindow* window)
{
    
}

void GUIObject::Update(float delta)
{
    _hovered = IsHovered();
    
    if(IsClicked())
        Click();
}

bool GUIObject::IsClicked()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && IsHovered();
}

bool GUIObject::IsHovered()
{
    return _boundingBox.contains(sf::Mouse::getPosition(*window));
}