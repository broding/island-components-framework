//
//  PhysicsComponent.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__PhysicsComponent__
#define __Island__PhysicsComponent__

#include <iostream>
#include "Component.h"

// forward declare
class PhysicsSystem;

class PhysicsComponent : public Component
{
private:
public:
    PhysicsComponent();
    
    static PhysicsSystem* physicsSystem;
    
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f forceAccumulated;
    float mass;
};

#endif /* defined(__Island__PhysicsComponent__) */
