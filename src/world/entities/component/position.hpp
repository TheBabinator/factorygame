#pragma once
#include <cmath>
#define PI 3.14159265358979323846

namespace Component
{
    class Position
    {
    public:
        float x;
        float y;
        float rotation;
        float distance(Position other);
    };
}
