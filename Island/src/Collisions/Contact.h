//
//  Contact.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_Contact_h
#define Island_Contact_h

#include <SFML/System.hpp>

struct Contact {
    sf::Vector2f point;
    sf::Vector2f normal;
    float penetration;
};

#endif
