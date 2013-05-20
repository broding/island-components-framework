//
//  Pack.h
//  Island
//
//  Created by Bas Roding on 20-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Pack__
#define __Island__Pack__

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Sprite.h"

struct TextureData
{
    TextureData() {};
    TextureData(std::string name, sf::Texture* texture, sf::IntRect rectangle) : name(name), texture(texture), rectangle(rectangle) {};
    
    std::string name;
    sf::Texture* texture;
    sf::IntRect rectangle;
};

class Pack
{
public:
    Pack();
    Pack(std::string name);
    ~Pack();
    Sprite GetSprite(std::string name);
    bool HasSprite(std::string name);
private:
    std::string _name;
    sf::Texture* _texture;
    std::map<std::string, TextureData> _textureData;
};

#endif /* defined(__Island__Pack__) */
