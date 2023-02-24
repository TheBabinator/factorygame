#pragma once
#include <iostream>
#include <queue>
#include "core/graphics.hpp"
#include "core/gui.hpp"
#include "core/input.hpp"
#include "content/loadingscreen.hpp"
#include "content/tiles.hpp"
#include "content/entities.hpp"
#include "gui/menuscreen.hpp"
#include "world/map.hpp"
#include "world/entities/player.hpp"

namespace Gamestate
{
    enum State
    {
        QUIT,
        LOADING,
        MENU,
        GAMETEST,
    };

    extern State currentState;
    extern World::Map* loadedMap;
    extern World::PlayerEntity* player;

    void update(int deltaTicks);
    void init();
    void kill();

    void prepareGametest();
}
