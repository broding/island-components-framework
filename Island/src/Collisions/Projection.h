//
//  Projection.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__Projection__
#define __Island__Projection__

#include <iostream>

class Projection
{
public:
    Projection(float min, float max);
    bool IsOverlapping(Projection other);
    float GetOverlap(Projection other);
    
    float min;
    float max;
};

#endif /* defined(__Island__Projection__) */
