#include "core/gamestate.hpp"

namespace Gamestate
{
    State currentState = Gamestate::LOADING;
    World::Map* loadedMap = NULL;
    World::PlayerEntity* player = NULL;

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
                    Graphics::cameraY -= deltaTicks * 0.01;
                if (Input::getKeyState("down"))
                    Graphics::cameraY += deltaTicks * 0.01;
                if (Input::getKeyState("left"))
                    Graphics::cameraX -= deltaTicks * 0.01;
                if (Input::getKeyState("right"))
                    Graphics::cameraX += deltaTicks * 0.01;
                Graphics::cameraZoom += Input::scrollY * 4.0;

                loadedMap->update(deltaTicks);
                player->update(deltaTicks);
                player->rotation += deltaTicks * 0.001;
                player->vx = 3.0 * std::cos(player->rotation);
                player->vy = 3.0 * std::sin(player->rotation);
                loadedMap->draw();
                player->draw();

                break;
        }
    }

    void init()
    {
        GUI::loadAssets();
        Tiles::addContent();
        Entities::addContent();
    }

    void kill()
    {
        GUI::unloadAssets();
        Tiles::removeContent();
        Entities::removeContent();
    }

    void prepareGametest()
    {
        currentState = State::GAMETEST;
        loadedMap = new World::Map();
        player = new World::PlayerEntity(0, Entities::player);
    }
}
