#ifndef EDITOR_INTERFACE
#define EDITOR_INTERFACE

#include <SFML/Graphics.hpp>

#define DllExport _declspec(dllexport)

extern "C" DllExport int OpenWindow();
extern "C" DllExport void CloseWindow();
extern "C" DllExport int Update();
extern "C" DllExport void ChangeTool(int tool);

sf::RenderWindow* window;
Core* core;

#endif