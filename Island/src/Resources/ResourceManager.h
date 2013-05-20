//
//  ResourceManager.h
//  Island
//
//  Created by Bas Roding on 17-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__ResourceManager__
#define __Island__ResourceManager__

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Sprite.h"

#include "Pack.h"

class ResourceManager
{
public:
    static ResourceManager* GetInstance();
    
    bool LoadPack(std::string name);
    bool UnloadPack(std::string name);
    
    Sprite GetSprite(std::string name);
    Sprite GetSprite(std::string name, std::string pack);
private:
    ResourceManager();
    static ResourceManager* _instance;
    
    std::map<std::string, Pack*> _packs;
};

#endif /* defined(__Island__ResourceManager__) */
