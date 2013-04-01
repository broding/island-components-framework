//
//  EasingUtil.h
//  Island
//
//  Created by Bas Roding on 31-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_EasingUtil_h
#define Island_EasingUtil_h

class EasingUtil
{
    template <class T>
    
    static T QuadraticIn(float time, T start, T change, float duration)
    {
        time /= duration;
        return change*time*time + start;
    }
}

#endif
