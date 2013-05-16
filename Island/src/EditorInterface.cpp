#include "ResourcePath.hpp"
#include "Core.h"
#include "EditorCore.h"
#include "EditorInterface.h"
#include <sstream>

int OpenWindow()
{
	// Create the main window
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Island");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    core = new EditorCore(window);
    
    return 1;
}

void CloseWindow()
{
	window->close();
	delete window;
}

int Update()
{
	if(window->isOpen())
	{
		sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            // Espace pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }
        
        window->clear();
    
        core->Update(0.0016f);

        // Update the window
        window->display();

		return 1;
	}

	return 0;
}

void ChangeTool(int tool)
{
	core->currentTool = (Tool)tool;
}

unsigned int GetSelectedEntityId()
{
	if(core->GetSelectedEntity() != 0)
    {
		return core->GetSelectedEntity()->_id;
    }

	return 0;
}

const char* GetSelectedEntityXML()
{
	if(core->GetSelectedEntity() != 0)
    {
		xmlDocument.reset();
        core->GetSelectedEntity()->FillXML(xmlDocument.append_child());
        
		std::stringstream ss;
		xmlDocument.save(ss);

		char *p = new char[ss.str().size()+1];
		strcpy(p, ss.str().c_str());

		return p;
    }

	return NULL;
}

const char* GetSceneXML()
{
	xmlDocument.reset();
    core->FillXML(xmlDocument.append_child("scene"));
        
	std::stringstream ss;
	xmlDocument.save(ss);

	char *p = new char[ss.str().size()+1];
	strcpy(p, ss.str().c_str());

	return p;
}


void SendEntityXML(const char* xml, int size)
{
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_buffer(xml, size);
	
	if(result)
		core->GetSelectedEntity()->UpdateFromXML(document);
	else
		core->GetSelectedEntity()->_id = 999;
}

void ClearScene()
{
	core->ClearScene();
}