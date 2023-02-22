#pragma once
#include "content/registry.hpp"
#include "world/tiles/ground.hpp"

namespace Tiles
{
    extern World::Ground *dirt, *grass, *squares;

    void addContent();
    void removeContent();
}
