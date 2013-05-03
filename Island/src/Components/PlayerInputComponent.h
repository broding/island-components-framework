//
//  PlayerInputComponent.h
//  Island
//
//  Created by Bas Roding on 20-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PlayerInputComponent__
#define __Island__PlayerInputComponent__

#include <iostream>
#include "Component.h"
#include "PlayerInputSystem.h"
#include <SFML/Window/Keyboard.hpp>

class PlayerInputComponent : public Component
{
private:
public:
    PlayerInputComponent();
    pugi::xml_node CreateXML();
    void UpdateFromXML(pugi::xml_node node);
    
    static PlayerInputSystem* playerInputSystem;
    
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key shoot;
    
    float speed;
    float runSpeed;
    
};

#endif /* defined(__Island__PlayerInputComponent__) */
