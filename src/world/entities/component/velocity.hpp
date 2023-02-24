#pragma once
#include <iostream>
#include "world/entities/component/position.hpp"

namespace Component
{
    class Velocity : virtual public Position
    {
    public:
        float vx;
        float vy;
        void update(int deltaTicks);
    };
}

