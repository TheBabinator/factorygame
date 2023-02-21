#include "core/gamestate.hpp"

namespace Gamestate
{
    State currentState = Gamestate::LOADING;
    World::Map* loadedMap = NULL;

    void update(int deltaTicks)
    {
        switch (currentState)
        {
            default:
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
        loadedMap->loadChunk(0, 0);
    }
}
