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
                if (Input::getKeyState("up"))
                    Graphics::cameraY -= deltaTicks / 100.0;
                if (Input::getKeyState("down"))
                    Graphics::cameraY += deltaTicks / 100.0;
                if (Input::getKeyState("left"))
                    Graphics::cameraX -= deltaTicks / 100.0;
                if (Input::getKeyState("right"))
                    Graphics::cameraX += deltaTicks / 100.0;
                Graphics::cameraZoom += Input::scrollY * 4;
                Input::inputText = "";
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
    }
}
