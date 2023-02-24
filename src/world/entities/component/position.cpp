#include "world/entities/component/position.hpp"

namespace Component
{
    float Position::distance(Position other)
    {
        float xdist = other.x - x;
        float ydist = other.y - y;
        return std::sqrt(xdist * xdist + ydist * ydist);
    }
}
