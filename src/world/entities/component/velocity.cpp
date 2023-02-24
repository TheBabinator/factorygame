#include "world/entities/component/velocity.hpp"

namespace Component
{
    void Velocity::update(int deltaTicks)
    {
        x += vx * deltaTicks * 0.001;
        y += vy * deltaTicks * 0.001;
    }
}
