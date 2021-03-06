//
//  BulletScript.h
//  Island
//
//  Created by Bas Roding on 28-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__BulletScript__
#define __Island__BulletScript__

#include <iostream>
#include "BaseScript.h"
#include "Entity.h"

class BulletScript : public BaseScript
{
public:
	BulletScript()
	{
		time = 0.0f;
	}
    
    void RunScript(Entity* entity, float lastFrameTime)
    {
        time += lastFrameTime;
        
        if(time > 2)
            entity->Delete();
    }

private:
    float time;
};

#endif /* defined(__Island__BulletScript__) */
