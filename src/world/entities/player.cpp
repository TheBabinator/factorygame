#include "world/entities/player.hpp"

namespace World
{
    void PlayerEntity::update(int deltaTicks)
    {
        DrawableEntity::update(deltaTicks);
        Component::Velocity::update(deltaTicks);
    }
}
