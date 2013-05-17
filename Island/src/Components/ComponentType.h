//
//  ComponentType.h
//  Island
//
//  Created by Bas Roding on 19-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_ComponentType_h
#define Island_ComponentType_h

#include <pugixml.hpp>

enum ComponentType
{
    COMPONENT_RENDER,
    COMPONENT_TRANSFORM,
    COMPONENT_PHYSICS,
    COMPONENT_PLAYERINPUT,
    COMPONENT_NETWORK,
    COMPONENT_CAMERA,
    COMPONENT_BOXCOLLISION,
    COMPONENT_SPHERECOLLISION,
    COMPONENT_HEALTH,
    COMPONENT_WEAPON,
    COMPONENT_SCRIPT,
    COMPONENT_DAMAGE
};

inline void FillDocument(pugi::xml_node& node, std::string name, ComponentType type)
{
	pugi::xml_node componentNode = node.append_child("component");
	componentNode.append_attribute("name").set_value(name.c_str());
	componentNode.append_attribute("type").set_value(type);
}

inline void GetComponentList(pugi::xml_document& doc)
{
	pugi::xml_node components = doc.append_child("components");

	FillDocument(components, "Render", COMPONENT_RENDER);
	FillDocument(components, "Transform", COMPONENT_TRANSFORM);
	FillDocument(components, "Physics", COMPONENT_PHYSICS);
	FillDocument(components, "Player Input", COMPONENT_PLAYERINPUT);
	FillDocument(components, "Network", COMPONENT_NETWORK);
	FillDocument(components, "Camera", COMPONENT_CAMERA);
	FillDocument(components, "Box Collision", COMPONENT_BOXCOLLISION);
	FillDocument(components, "Sphere Collision", COMPONENT_SPHERECOLLISION);
	FillDocument(components, "Health", COMPONENT_HEALTH);
	FillDocument(components, "Weapon", COMPONENT_WEAPON);
	FillDocument(components, "Script", COMPONENT_SCRIPT);
	FillDocument(components, "Damage", COMPONENT_DAMAGE);
}

#endif
