//
//  IGUIObject.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_GUIObject_h
#define Island_GUIObject_h

#include <SFML/Graphics.hpp>

class GUIObject
{
private:
    bool IsClicked();
    bool IsHovered();
protected:
    sf::IntRect _boundingBox;
    bool _hovered;
    bool _clicked;
public:
    static sf::Window* window;
    
    sf::Vector2f position;
    
    virtual void Select();
    virtual void Click();
    virtual sf::Rect<int> GetBoundingBox();
    virtual void Draw(sf::RenderWindow* window);
    virtual void Update(float delta);
};

#endif
