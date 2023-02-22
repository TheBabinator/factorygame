#include "core/gamestate.hpp"

namespace Gamestate
{
    State currentState = Gamestate::LOADING;
    World::Map* loadedMap = NULL;

    void update(int deltaTicks)
    {
        switch (currentState)
        {
            case QUIT:
                break;
            case LOADING:
                if (LoadingScreen::run()) currentState = Gamestate::MENU;
                break;
            case MENU:
                Menuscreen::run();
                break;
            case GAMETEST:
                loadedMap->update();
                loadedMap->draw();
                break;
        }
    }

    void init()
    {
        GUI::loadAssets();
        Tiles::addContent();
    }

    void kill()
    {
        GUI::unloadAssets();
        Tiles::removeContent();
    }

    void prepareGametest()
    {
        currentState = State::GAMETEST;
        loadedMap = new World::Map();
        for (int cy = -1; cy <= 1; cy++)
        {
            for (int cx = -1; cx <= 1; cx++)
            {
                loadedMap->loadChunk(cx, cy);
            }
        }
    }
}
