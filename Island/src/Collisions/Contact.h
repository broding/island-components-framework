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
    
    bool operator==(const Contact& other)
    {
        return (other.entity1 == entity1 && other.entity2 == entity2) || (other.entity1 == entity2 && other.entity2 == entity1);
            
    }
};

struct ContactList
{
private:
    std::vector<Contact> _contacts;
public:
    void AddContact(Contact contact)
    {
        for (std::vector<Contact>::iterator it = _contacts.begin(), end = _contacts.end(); it != end; ++it)
            if((*it) == contact)
                return;
        
        _contacts.push_back(contact);
    }
    
    std::vector<Contact> GetContacts()
    {
        return _contacts;
    }

    
};

#endif
