#pragma once
#include <iostream>
#include <queue>
#include "core/gui.hpp"
#include "content/loadingscreen.hpp"
#include "content/tiles.hpp"
#include "gui/menuscreen.hpp"
#include "world/map.hpp"

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

    void update(int deltaTicks);
    void init();
    void kill();

    void prepareGametest();
}
