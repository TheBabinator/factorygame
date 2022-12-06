#pragma once
#include <iostream>
#include <queue>
#include <SDL.h>
#include <SDL_image.h>

namespace SDLManager
{
    extern int screenWidth;
    extern int screenHeight;
    extern long long totalTicks;
    extern long long lastTicks;
    extern int deltaTicks;

    extern SDL_Window* window;
    extern SDL_Surface* screenSurface;
    extern SDL_Renderer* renderer;

    bool initSDL();
    void close();

    void test();

    void preFrame();
    void postFrame();

    std::queue<SDL_Event> pollEvents();
};
