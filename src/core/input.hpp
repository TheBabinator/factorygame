#pragma once
#include <iostream>
#include <string>
#include <map>
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
    extern int scrollX;
    extern int scrollY;

    class KeyBinding
    {
    public:
        int keyCode;
        int state;
        void update();
        KeyBinding(int defaultKey);
    };

    extern std::map<std::string, KeyBinding*> keyBindings;
    int getKeyState(std::string name);

    void preUpdate();
    void handleEvent(SDL_Event e);
    void update();
}
