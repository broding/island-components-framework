//
//  ResourceManager.cpp
//  Island
//
//  Created by Bas Roding on 17-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ResourceManager.h"
#include "ResourcePath.hpp"

ResourceManager* ResourceManager::_instance = 0;

ResourceManager* ResourceManager::GetInstance()
{
    if(_instance == 0)
        _instance = new ResourceManager();
    
    return _instance;
}

ResourceManager::ResourceManager()
{
    
}

bool ResourceManager::LoadPack(std::string name)
{
    if(_packs.find(name) == _packs.end())
        _packs[name] = new Pack(name);
    
    return true;
}

bool ResourceManager::UnloadPack(std::string name)
{
    if(_packs.find(name) == _packs.end())
    {
        delete _packs[name];
        return true;
    }
    
    return false;
}

Sprite ResourceManager::GetSprite(std::string name)
{
    for(std::map<std::string,Pack*>::iterator iter = _packs.begin(); iter != _packs.end(); ++iter)
    {
        if(iter->second->HasSprite(name))
            return iter->second->GetSprite(name);
        else
            continue;
    }
    
    Sprite dummy;
    return dummy;
}

Sprite ResourceManager::GetSprite(std::string name, std::string pack)
{
    if(_packs.find(pack) == _packs.end())
        std::cout << "Tried to load sprite from unknown pack: " << pack;
    
    Sprite sprite = _packs[pack]->GetSprite(name);
    return sprite;
}
