//
//  Sprite.h
//  Island
//
//  Created by Bas Roding on 20-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Sprite__
#define __Island__Sprite__

#include <iostream>
#include <SFML/Graphics.hpp>

class Sprite : public sf::Sprite
{
public:
    std::string getName()
    {
        return _name;
    }
    
    void setName(std::string name)
    {
        _name = name;
    }
private:
    std::string _name;
};

#endif /* defined(__Island__Sprite__) */
