//
//  Button.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Button__
#define __Island__Button__

#include <iostream>
#include "GUIObject.h"
#include <SFML/Graphics.hpp>

enum ButtonState
{
    BUTTON_NORMAL = 1,
    BUTTON_HOVERED,
    BUTTON_PUSHED
};

class Button : public GUIObject
{
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    ButtonState _buttonState;
public:
    Button();
    virtual void Update(float delta);
    virtual void Click();
    virtual void Draw(sf::RenderWindow* window);
};

#endif /* defined(__Island__Button__) */
