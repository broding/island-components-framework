//
//  CommonUtil.h
//  Island
//
//  Created by Bas Roding on 30-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__CommonUtil__
#define __Island__CommonUtil__

#include <iostream>

class CommonUtil
{
public:
    
    template <class T>
    static T Lerp(float time, T a, T b)
    {
        return (1-time)*a + time*b;
    }
};

#endif /* defined(__Island__CommonUtil__) */
