//
//  QuadTree.h
//  Island
//
//  Created by Bas Roding on 25-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_QuadTree_h
#define Island_QuadTree_h

#include <vector>
#include <SFML/System.hpp>
#include "Entity.h"

class QuadTreeNode
{
private:
    static const int _maxNodes = 4;
    
    int _level;
    QuadTreeNode* _nodes;
    sf::Rect<float> _rectangle;
    std::vector<Entity*> _entities;
    bool _hasLeafs;
    
    void split();
public:
    QuadTreeNode(int level, sf::Rect<float>);
    ~QuadTreeNode();
    void insert(Entity* entity);
    void remove(Entity* entity);
};

class QuadTree
{
private:
    QuadTreeNode _node;
public:
};

#endif
