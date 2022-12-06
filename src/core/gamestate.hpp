#pragma once
#include <iostream>
#include <queue>
#include "core/graphics.hpp"
#include "core/gui.hpp"
#include "core/input.hpp"
#include "content/loadingscreen.hpp"
#include "content/tiles.hpp"

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

    void update(int deltaTicks);
    void init();
    void kill();

    void prepareGametest();
}
