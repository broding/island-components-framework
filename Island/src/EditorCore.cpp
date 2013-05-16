//
//  EditorCore.cpp
//  Island
//
//  Created by Bas Roding on 03-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include <string>
#include "EditorCore.h"
#include "EditorScene.h"
#include "GameConfig.h"
#include "TransformComponent.h"
#include "CameraComponent.h"

EditorCore::EditorCore(sf::RenderWindow* window) : Core(window)
{
    GameConfig::GetInstance()->SetFlagConfig("editorMode", true);
	GameConfig::GetInstance()->SetFlagConfig("debugMode", true);

    SwitchScene(new EditorScene());
    
    currentTool = SELECT;
	_selectedEntity = 0;
	_draggingEntity = false;
}

void EditorCore::Update(float lastFrameTime)
{
    Core::Update(lastFrameTime);
    
    // entity selection
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentTool == SELECT)
    {
		Entity* newSelected = SelectEntity();

		if(newSelected != NULL)
			_selectedEntity = SelectEntity();
    }

	// entity drag
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentTool == DRAG &&  !_draggingEntity)
    {
		Entity* newSelected = SelectEntity();

		if(newSelected != NULL)
		{
			_draggingEntity = true;
			_selectedEntity = SelectEntity();
		}
    }

	if(_draggingEntity)
		_selectedEntity->GetComponent<TransformComponent>()->position = _renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*_renderWindow));

	if(currentTool == DRAG && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		_draggingEntity = false;


    // camera drag
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        if(!_rightMouseWasPressed)
        {
            _dragMouseStart = sf::Mouse::getPosition();
            _dragCameraStart = _cameraSystem->currentCamera->GetOwner()->GetComponent<TransformComponent>()->position;
        }
        else
        {
            sf::Vector2i mouseDelta = sf::Mouse::getPosition() - _dragMouseStart;
            _cameraSystem->currentCamera->GetOwner()->GetComponent<TransformComponent>()->position = _dragCameraStart - sf::Vector2f(mouseDelta.x, mouseDelta.y);
        }
    }
    
	_leftMouseWasPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    _rightMouseWasPressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    
    // camera zoom
    sf::Event event;
    while (_renderWindow->pollEvent(event))
    {
        if (event.type == sf::Event::MouseWheelMoved)
        {
            if(event.mouseWheel.delta != 0)
                _cameraSystem->currentCamera->zoom -= event.mouseWheel.delta * 0.07 * _cameraSystem->currentCamera->zoom;
            
        }
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

void EditorCore::FillXML(pugi::xml_node node)
{
    EditorScene* scene = dynamic_cast<EditorScene*>(_currentScene);
    
    for (std::vector<Entity*>::const_iterator iterator = scene->GetEntities().begin(), end = scene->GetEntities().end(); iterator != end; ++iterator)
    {
        (*iterator)->FillXML(node.append_child());
    }
}

void EditorCore::ClearScene()
{
	SwitchScene(new EditorScene());
}
