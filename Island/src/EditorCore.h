//
//  EditorCore.h
//  Island
//
//  Created by Bas Roding on 03-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef __Island__EditorCore__
#define __Island__EditorCore__

#include <iostream>
#include "Core.h"

enum Tool
{
    SELECT = 0,
    DRAG
};

class EditorCore : public Core
{
public:
    EditorCore(sf::RenderWindow* window);
    void Update(float lastFrameTime);
    Entity* GetSelectedEntity();
	void ClearScene();
    void FillXML(pugi::xml_node node);
	void UpdateFromXML(pugi::xml_node node);
    
    Tool currentTool;
private:
    bool _leftMouseWasPressed;
    bool _rightMouseWasPressed;
    sf::Vector2i _dragMouseStart;
    sf::Vector2f _dragCameraStart;
	bool _draggingEntity;
    
    Entity* SelectEntity();
    
    Entity* _selectedEntity;
};

#endif /* defined(__Island__EditorCore__) */
