//
//  Button.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Button.h"
#include <ResourcePath.hpp>

Button::Button()
{
    _texture.loadFromFile(resourcePath() + "icon.png");
    _normalState.setTexture(_texture);
    _boundingBox = sf::Rect<int>(0, 0, _texture.getSize().x, _texture.getSize().y);
}

Button::~Button()
{
    
}

void Button::Click()
{
    
}

void Button::Draw(sf::RenderWindow* window)
{
    window->draw(_normalState);
}