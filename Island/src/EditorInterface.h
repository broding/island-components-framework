#ifndef WINDOWS
#define _declspec(dllexport)
#endif

#ifndef EDITOR_INTERFACE
#define EDITOR_INTERFACE

#include "Core.h"
#include <SFML/Graphics.hpp>

#define DllExport extern "C" _declspec(dllexport)

DllExport int OpenWindow();
DllExport void CloseWindow();
DllExport int Update();
DllExport void ChangeTool(int tool);
DllExport char* GetSelectedEntity();

sf::RenderWindow* window;
EditorCore* core;

#endif