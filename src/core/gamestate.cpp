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
                player->vx = 0;
                player->vy = 0;
                if (Input::getKeyState("up"))
                    player->vy -= 4;
                if (Input::getKeyState("down"))
                    player->vy += 4;
                if (Input::getKeyState("left"))
                    player->vx -= 4;
                if (Input::getKeyState("right"))
                    player->vx += 4;
                player->rotation += deltaTicks * 0.001;

                loadedMap->update(deltaTicks);
                player->update(deltaTicks);
                loadedMap->draw();
                player->draw();

                Graphics::cameraX = player->x;
                Graphics::cameraY = player->y;
                Graphics::cameraZoom += Input::scrollY * 4.0;

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
