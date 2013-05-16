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
    GUIObject::GUIObject();
    
    _texture.loadFromFile(resourcePath() + "testbutton.png");
    _sprite.setTexture(_texture);
    _boundingBox = sf::IntRect(0, 0, _texture.getSize().x, _texture.getSize().y / 3);
    _buttonState = BUTTON_NORMAL;
}

void Button::Click()
{
    GUIEvent event(this->GetId(), GUIEvent::BUTTON_CLICKED);
    
    SendEventToObservers(event);
}

void Button::Update(float delta)
{
    _buttonState = BUTTON_NORMAL;
    
    GUIObject::Update(delta);
    
    if(_hovered)
        _buttonState = BUTTON_HOVERED;
    if(_clicked)
        _buttonState = BUTTON_PUSHED;
        
}

void Button::Draw(sf::RenderWindow* window)
{
    _sprite.setPosition(position);
    _sprite.setTextureRect(sf::IntRect(0, _texture.getSize().y / 3 * (_buttonState - 1), _texture.getSize().x, _texture.getSize().y / 3));
    window->draw(_sprite);
}