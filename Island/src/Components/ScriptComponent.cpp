//
//  ScriptComponent.cpp
//  Island
//
//  Created by Bas Roding on 27-04-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "ScriptComponent.h"

ScriptSystem* ScriptComponent::scriptSystem;

ScriptComponent::ScriptComponent()
{
    _type = COMPONENT_SCRIPT;
    _subSystem = scriptSystem;
    
    this->AddToSystem();
}

ScriptComponent::~ScriptComponent()
{
    delete script;
}



pugi::xml_node ScriptComponent::CreateXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("velocity");
    dataNode.append_attribute("value").set_value(145);
    
    return node;
}

void ScriptComponent::UpdateFromXML(pugi::xml_node node)
{
    
}