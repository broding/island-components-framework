//
//  TransformComponent.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__TransformComponent__
#define __Island__TransformComponent__

#include <iostream>
#include "Component.h"
#include "TransformSystem.h"
#include "../Network/INetworkableComponent.h"
#include <SFML/Graphics.hpp>

class TransformComponent : public Component, public INetworkableComponent
{
private:
public:
    TransformComponent();
    
    virtual const void* GenerateNetworkPacket();
    virtual void ApplyNetworkPacket();
    virtual void DrawDebug(sf::RenderWindow* window);
    
    static TransformSystem* transformSystem;
    
    sf::Vector2f previousPosition;
    
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f scale;
    float rotation;
    sf::Vector2f origin;
};

#endif /* defined(__Island__TransformComponent__) */
