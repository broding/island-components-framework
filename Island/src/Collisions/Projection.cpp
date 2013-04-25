//
//  Projection.cpp
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Projection.h"
#include <algorithm>

Projection::Projection(float min, float max) : min(min), max(max)
{
    if(max < min)
        throw std::exception();
}

bool Projection::IsOverlapping(Projection other)
{
    return !(this->min > other.max || other.min > this->max);
}

float Projection::GetOverlap(Projection other)
{
    if (IsOverlapping(other))
        return std::min(max, other.max) - std::max(min, other.min);
    
    return 0;
}
