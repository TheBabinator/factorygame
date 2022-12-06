#pragma once
#include "content/registry.hpp"
#include "world/tiles/ground.hpp"

namespace Tiles
{
    extern World::Ground* dirt;
    extern World::Ground* grass;
    void addContent();
    void removeContent();
}
