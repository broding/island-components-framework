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
    if(max <= min)
        throw std::exception();
}

bool Projection::IsOverlapping(Projection other)
{
    if(min < other.min)
    {
        // other on top
        if(max >= other.min)
            return true;
        else
            return false;
        
    }
    else if(min > other.min)
    {
        // ours on top
        if(min < other.max)
            return true;
        else
            return false;
    }
    else
        return true;
    
    return false;
}

float Projection::GetOverlap(Projection other)
{
    if(min < other.min)
    {
        if(max > other.min)
            return other.max - other.min;
        else if(max <= other.min)
            return max - other.min;
        else
            return 0;
    }
    else if(min > other.min)
    {
        if(other.max > min)
            return max - min;
        else if(other.max <= min)
            return other.max - min;
        else
            return 0;
    }
    else if(min == other.min)
    {
        if(other.max <= max)
            return max - min;
        else
            return max - min;
    }
    
    return 0;
}
