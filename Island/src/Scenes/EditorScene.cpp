//
//  EditorScene.cpp
//  Island
//
//  Created by Bas Roding on 03-05-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "EditorScene.h"
#include "PlayerFactory.h"
#include "CommonFactory.h"
#include "StructureFactory.h"
#include "CameraComponent.h"
#include "ResourcePath.hpp"

EditorScene::EditorScene()
{
    Entity* camera = CommonFactory::CreateCamera();
    
    AddEntity(camera);

}

void EditorScene::ProcessGUIEvent(GUIEvent event)
{
    
}

const std::vector<Entity*>& EditorScene::GetEntities()
{
    return _entities;
}