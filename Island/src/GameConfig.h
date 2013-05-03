//
//  GameSettings.h
//  Island
//
//  Created by Bas Roding on 28-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__GameConfig__
#define __Island__GameConfig__

#include <iostream>
#include <map>

class GameConfig
{
public:
    static GameConfig* GetInstance();
    
    float GetNumberConfig(std::string config);
    bool GetFlagConfig(std::string config);
    void SetFlagConfig(std::string config, bool flag);
private:
    GameConfig();
    
    static GameConfig* _instance;
    static bool _isInitialized;
    
    std::map<std::string, float> _numberConfig;
    std::map<std::string, bool> _flagConfig;
};

#endif /* defined(__Island__GameConfig__) */
