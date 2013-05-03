//
//  EditorCore.cpp
//  Island
//
//  Created by Bas Roding on 03-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "EditorCore.h"
#include "EditorScene.h"
#include "GameConfig.h"
#include "TransformComponent.h"

EditorCore::EditorCore(sf::RenderWindow* window) : Core(window)
{
    GameConfig::GetInstance()->SetFlagConfig("editorMode", true);
    SwitchScene(new EditorScene());
    
    currentTool = SELECT;
}

void EditorCore::Update(float lastFrameTime)
{
    Core::Update(lastFrameTime);
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (currentTool == SELECT || currentTool == DRAG))
    {
        _selectedEntity = SelectEntity();
    }
}

Entity* EditorCore::SelectEntity()
{
    EditorScene* scene = dynamic_cast<EditorScene*>(_currentScene);
    if(scene != NULL)
    {
        for (std::vector<Entity*>::const_iterator iterator = scene->GetEntities().begin(), end = scene->GetEntities().end(); iterator != end; ++iterator)
        {
            
            TransformComponent* transform = (*iterator)->GetComponent<TransformComponent>();
            
            if(transform != NULL)
            {
                sf::Rect<int> rect(transform->position.x - 8, transform->position.y - 8, 16, 16);
                sf::Vector2f tempMousePos = _renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*_renderWindow));
                sf::Vector2i mousePos(tempMousePos.x, tempMousePos.y);
                
                if(rect.contains(mousePos))
                    return (*iterator);
            }
        }
    }
    
    return NULL;
}

Entity* EditorCore::GetSelectedEntity()
{
    return _selectedEntity;
}
