//
//  IGUIObject.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_IGUIObject_h
#define Island_IGUIObject_h

#include <SFML/Graphics/Rect.hpp>

class IGUIObject
{
private:
    sf::Rect<int> boundingBox;
public:
    virtual void Select() = 0;
    virtual void Click() = 0;
    virtual sf::Rect<int> GetBoundingBox() = 0;
    virtual void Draw() = 0;
    virtual void Update(float delta) = 0;
};

#endif
