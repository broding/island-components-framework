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
#include <vector>
#include "Entity.h"

struct Contact {
    Entity* entity1;
    Entity* entity2;
    sf::Vector2f normal;
    float penetration;
};

struct ContactList
{
    std::vector<Contact> contacts;
    int nrOfContacts;
};

#endif
