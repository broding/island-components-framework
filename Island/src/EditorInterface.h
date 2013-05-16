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
DllExport unsigned int GetSelectedEntityId();
DllExport const char* GetSelectedEntityXML();
DllExport const char* GetSceneXML();
DllExport void SendEntityXML(const char* xmlWide, int size);
DllExport void ClearScene();

sf::RenderWindow* window;
EditorCore* core;
pugi::xml_document xmlDocument;

#endif