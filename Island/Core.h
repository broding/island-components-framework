//
//  Core.h
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Core__
#define __Island__Core__

#include <iostream>
#include <SFML/Graphics.hpp>

class Core
{
private:
public:
    void Update(double delta);
    void Draw(sf::RenderWindow* window, double delta);
};

#endif /* defined(__Island__Core__) */
