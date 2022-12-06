#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

namespace Input
{
    extern bool allowInputText;
    extern std::string inputText;

    extern int mouseX;
    extern int mouseY;
    extern int leftMouse;
    extern int rightMouse;
    extern int middleMouse;

    void handleEvent(SDL_Event e);
    void update();
}
