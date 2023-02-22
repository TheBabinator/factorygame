#include <iostream>
#include <queue>
#include <SDL.h>
#include "core/sdlmanager.hpp"
#include "core/input.hpp"
#include "core/gamestate.hpp"

int main(int argc, char* args[])
{
    std::cout << "hello world!" << std::endl;
    srand(time(NULL));
    bool sdl = SDLManager::initSDL();
    if (sdl) {
        Gamestate::init();

        while (true) {
            SDLManager::preFrame();
            // input handling
            std::queue<SDL_Event> events = SDLManager::pollEvents();
            while (!events.empty())
            {
                SDL_Event e = events.front();
                events.pop();
                if (e.type == SDL_QUIT) Gamestate::currentState = Gamestate::QUIT;
                Input::handleEvent(e);
            }
            Input::update();
            // call game state
            Gamestate::update(SDLManager::deltaTicks);
            // done
            if (Gamestate::currentState == Gamestate::QUIT) break;
            SDLManager::postFrame();
        }

        Gamestate::kill();
    }
    SDLManager::close();
    return 0;
}
