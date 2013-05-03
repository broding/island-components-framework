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
    RenderComponent* renderComponent = new RenderComponent();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(resourcePath() + "ground001.png");
    texture->setSmooth(true);
    renderComponent->sprite.setTexture(*texture);
    renderComponent->tiling = sf::Vector2<unsigned int>(5, 5);
    TransformComponent* transformComponent = new TransformComponent();
    Entity* entity = new Entity();
    entity->AddComponent(renderComponent);
    entity->AddComponent(transformComponent);
    
    AddEntity(entity);
    
    AddEntity(StructureFactory::CreateWall(sf::Vector2f(300, 300), 0, 200, 40));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(50, -50), 32));
    
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(250, -520), 32));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(550, 250), 32));
    AddEntity(StructureFactory::CreateSphere(sf::Vector2f(90, -50), 16));
    
    Entity* camera = CommonFactory::CreateCamera();
    Entity* player = PlayerFactory::CreatePlayer();
    
    camera->GetComponent<CameraComponent>()->targetEntity = player;
    
    AddEntity(camera);
    AddEntity(player);

}

void EditorScene::ProcessGUIEvent(GUIEvent event)
{
    
}

const std::vector<Entity*> EditorScene::GetEntities()
{
    return _entities;
}