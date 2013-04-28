//
//  IGUIObject.h
//  Island
//
//  Created by Bas Roding on 27-03-13.
//  Copyright (c) 2013 Bas Roding. All rights reserved.
//

#ifndef Island_GUIObject_h
#define Island_GUIObject_h

#include <SFML/Graphics.hpp>
#include "GUIObserver.h"
#include "GUIEvent.h"
#include <list>

class GUIObject
{
private:
    std::list<GUIObserver*> _observers;
    bool IsClicked();
    bool IsHovered();
    unsigned int _id;
    static unsigned int _nextUniqueId;
protected:
    sf::IntRect _boundingBox;
    bool _hovered;
    bool _clicked;
public:
    static sf::RenderWindow* window;
    
    sf::Vector2f position;
    
    GUIObject();
    ~GUIObject();
    
    virtual void Select();
    virtual void Click();
    virtual sf::Rect<int> GetBoundingBox();
    virtual void Draw(sf::RenderWindow* window);
    virtual void Update(float delta);
    
    unsigned int GetId();
    
    void RegisterObserver(GUIObserver* observer);
    void UnregisterObserver(GUIObserver* observer);
    void SendEventToObservers(GUIEvent event);
};

#endif
