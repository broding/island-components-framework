//
//  NetworkComponent.cpp
//  Island
//
//  Created by Bas Roding on 25-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "NetworkComponent.h"

NetworkSystem* NetworkComponent::networkSystem;

NetworkComponent::NetworkComponent()
{
    _type = COMPONENT_PLAYERINPUT;
    _subSystem = networkSystem;
    
    this->AddToSystem();
    
    this->AddComponentSubscription(COMPONENT_NETWORK);
}



pugi::xml_node NetworkComponent::CreateXML(pugi::xml_node &node)
{
    pugi::xml_node dataNode;
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    dataNode = node.append_child("data");
    dataNode.append_attribute("type").set_value("position");
    dataNode.append_attribute("value").set_value(145);
    
    return node;
}

void NetworkComponent::UpdateFromXML(pugi::xml_node node)
{
    
}
