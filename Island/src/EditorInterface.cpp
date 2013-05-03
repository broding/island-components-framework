#include "ResourcePath.hpp"
#include "Core.h"
#include "EditorCore.h"
#include "EditorInterface.h"

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
	
}

int GetSelectedEntity()
{
    return core->GetSelectedEntity()->_id;
}