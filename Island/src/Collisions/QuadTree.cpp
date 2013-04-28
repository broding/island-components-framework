//
//  QuadTree.cpp
//  Island
//
//  Created by Bas Roding on 25-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "QuadTree.h"

QuadTreeNode::QuadTreeNode(int level, sf::Rect<float> rectangle) : _level(level), _rectangle(rectangle)
{
    _hasLeafs = false;
}

QuadTreeNode::~QuadTreeNode()
{
    if(_hasLeafs)
        for(int i = 0; i < 4; i++)
            delete &_nodes[i];
}

void QuadTreeNode::insert(Entity* entity)
{
    if(_entities.size() >= _maxNodes)
    {
        split();
    }
}

void QuadTreeNode::remove(Entity* entity)
{
}

void QuadTreeNode::split()
{
    float subWidth = _rectangle.width / 2;
    float subHeight = _rectangle.height / 2;
    
    _nodes[0] = *new QuadTreeNode(_level + 1, sf::Rect<float>(_rectangle.left, _rectangle.top, subWidth, subHeight));
    _nodes[1] = *new QuadTreeNode(_level + 1, sf::Rect<float>(_rectangle.left + subWidth, _rectangle.top, subWidth, subHeight));
    _nodes[2] = *new QuadTreeNode(_level + 1, sf::Rect<float>(_rectangle.left + subWidth, _rectangle.top + subHeight, subWidth, subHeight));
    _nodes[3] = *new QuadTreeNode(_level + 1, sf::Rect<float>(_rectangle.left, _rectangle.top + subHeight, subWidth, subHeight));
    
    _hasLeafs = false;
}