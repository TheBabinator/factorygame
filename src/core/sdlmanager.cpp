#include "core/sdlmanager.hpp"

int SDLManager::screenWidth = 0;
int SDLManager::screenHeight = 0;
long long SDLManager::totalTicks = 0;
long long SDLManager::lastTicks = 0;
int SDLManager::deltaTicks = 0;

SDL_Window* SDLManager::window = nullptr;
SDL_Surface* SDLManager::screenSurface = nullptr;
SDL_Renderer* SDLManager::renderer = nullptr;

bool SDLManager::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not init" << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");

    window = SDL_CreateWindow("what", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)
    {
        std::cout << "window could not be created" << SDL_GetError();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "renderer could not be created" << SDL_GetError();
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "image loading library didnt load" << IMG_GetError();
        return false;
    }

    SDL_Surface* iconSurface = IMG_Load("assets/icon.png");
    SDL_SetWindowIcon(window, iconSurface);
    SDL_FreeSurface(iconSurface);

    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    screenSurface = SDL_GetWindowSurface(window);
    std::cout << "window size is " << screenWidth << "x" << screenHeight << std::endl;
    return true;
}

void SDLManager::close()
{
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

std::queue<SDL_Event> SDLManager::pollEvents()
{
    std::queue<SDL_Event> events;
    while (true)
    {
        SDL_Event e;
        if (SDL_PollEvent(&e) == 0) return events;
        else events.push(e);
    }
}

void SDLManager::preFrame()
{
    totalTicks = SDL_GetTicks64();
    deltaTicks = totalTicks - lastTicks;
    //std::cout << "an extra " << deltaTicks << "ms has passed" << std::endl;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
}

void SDLManager::postFrame()
{
    lastTicks = totalTicks;
    SDL_RenderPresent(renderer);
}
