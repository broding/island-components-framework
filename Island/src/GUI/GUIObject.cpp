//
//  GUIObject.cpp
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#include "GUIObject.h"

sf::RenderWindow* GUIObject::window;
unsigned int GUIObject::_nextUniqueId = 0;

GUIObject::GUIObject()
{
    _id = _nextUniqueId++;
}

GUIObject::~GUIObject()
{
    _observers.clear();
}

void GUIObject::Select()
{
}

void GUIObject::Click()
{
    
}

sf::Rect<int> GUIObject::GetBoundingBox()
{
    return this->_boundingBox;
}

void GUIObject::Draw(sf::RenderWindow* window)
{
    
}

void GUIObject::Update(float delta)
{
    _hovered = IsHovered();
    _clicked = IsClicked();
    
    if(_clicked)
        Click();
}

bool GUIObject::IsClicked()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && IsHovered();
}

bool GUIObject::IsHovered()
{
    _boundingBox.left = position.x;
    _boundingBox.top = position.y;
    
    return _boundingBox.contains(sf::Mouse::getPosition(*window));
}

unsigned int GUIObject::GetId()
{
    return _id;
}

void GUIObject::RegisterObserver(GUIObserver *observer)
{
    _observers.push_back(observer);
}

void GUIObject::UnregisterObserver(GUIObserver *observer)
{
    _observers.remove(observer);
}

void GUIObject::SendEventToObservers(GUIEvent event)
{
    for (std::list<GUIObserver*>::iterator it = _observers.begin() ; it != _observers.end(); ++it)
        (*it)->ProcessGUIEvent(event);

}
