//
//  Pack.cpp
//  Island
//
//  Created by Bas Roding on 20-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Pack.h"
#include "pugixml.hpp"

Pack::Pack()
{
    _texture = 0;
}

Pack::Pack(std::string name) : _name(name)
{
    _texture = 0;
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("data/textures/common.xml");
    
    if(result)
    {
        _texture = new sf::Texture();
        _texture->loadFromFile("data/textures/common.png");
        _texture->setSmooth(true);
        
        for (pugi::xml_node spriteNode = doc.child("TextureAtlas").first_child(); spriteNode; spriteNode = spriteNode.next_sibling())
        {
            sf::IntRect rect(spriteNode.attribute("x").as_int(), spriteNode.attribute("y").as_int(), spriteNode.attribute("w").as_int(), spriteNode.attribute("h").as_int());
            
            TextureData data = TextureData(spriteNode.attribute("n").as_string(), _texture, rect);
            
            _textureData[spriteNode.attribute("n").as_string()] = data;
        }
    }
}

Pack::~Pack()
{
    delete _texture;
}

Sprite Pack::GetSprite(std::string name)
{
    Sprite sprite;
    sprite.setName(name);
    sprite.setTexture(*_texture);
    sprite.setTextureRect(_textureData[name].rectangle);
    
    return sprite;
}

bool Pack::HasSprite(std::string name)
{
    return _textureData.find(name) != _textureData.end();
}