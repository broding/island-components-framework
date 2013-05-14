//
//  Entity.cpp
//  Island
//
//  Created by Bas Roding on 18-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "Entity.h"
#include "Component.h"
#include "Scene.h"

unsigned int Entity::_idIncrementer = 1;

Entity::Entity(std::string name) : _name(name)
{
    _scene = NULL;
    enabled = true;
    _id = _idIncrementer++;
}

Entity::~Entity()
{
    while(!_components.empty()) delete _components.back(), _components.pop_back();
}

void Entity::SetParent(Scene *scene)
{
    _scene = scene;
}

Scene* Entity::GetParent()
{
    return _scene;
}

bool Entity::IsAddedToScene()
{
    return _scene != NULL;
}

void Entity::AddComponent(Component *component)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        (*iterator)->AddNeighbourComponent(component);
        component->AddNeighbourComponent(*iterator);
    }
    
    _components.push_back(component);
    component->SetOwner(this);
}

void Entity::RemoveComponent(ComponentType type)
{
    _deletedComponentTypes.push_back(type);
}

void Entity::CleanRemovedComponents()
{
    for (std::vector<ComponentType>::const_iterator typeIterator = _deletedComponentTypes.begin(), end = _deletedComponentTypes.end(); typeIterator != end; ++typeIterator)
    {
        for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
        {
            if((*iterator)->GetComponentType() == *typeIterator)
            {
                _components.remove(*iterator);
                delete *iterator;
                break;
            }
        }
    }
}

Component* Entity::GetComponent(ComponentType type)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
        if((*iterator)->GetComponentType() == type)
            return (*iterator);
    
    return NULL;
}

void Entity::HandleEvent(Event* event)
{
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        (*iterator)->HandleEvent(event);
    }
}

void Entity::Delete()
{
    if(IsAddedToScene())
        _scene->RemoveEntity(this);
}

void Entity::FillXML(pugi::xml_node node)
{
    node.set_name("entity");
    node.append_attribute("name").set_value(_name.c_str());
    node.append_attribute("id").set_value(_id);
    pugi::xml_node componentParentNode = node.append_child("components");
    
    for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
    {
        pugi::xml_node componentNode = componentParentNode.append_child();

		componentNode.set_name("component");
		componentNode.append_attribute("type").set_value((*iterator)->GetComponentType());
		componentNode.append_attribute("name").set_value((*iterator)->GetName().c_str());
        (*iterator)->FillXML(componentNode);
    }
}

void Entity::UpdateFromXML(pugi::xml_node document)
{
	_name = document.child("entity").attribute("name").as_string();
	
	pugi::xml_node components = document.child("entity").child("components");

	for (pugi::xml_node component = components.first_child(); component; component = component.next_sibling())
	{
        for (std::list<Component*>::const_iterator iterator = _components.begin(), end = _components.end(); iterator != end; ++iterator)
        {
            if((*iterator)->GetComponentType() == component.attribute("type").as_int())
            {
                (*iterator)->UpdateFromXML(component);
            }
        }
	}
}