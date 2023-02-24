#pragma once
#include <vector>
#include "content/registry.hpp"
#include "core/graphics.hpp"

namespace World
{
    class Tile;

    class TileClass : public Registry::Content
    {
    public:
        using Registry::Content::Content;
        void load();
        void unload();
        void draw(Tile* tile);
        int variants = 1;
    private:
        std::vector<Graphics::Region*> regions;
    };
}

#include "world/tile.hpp"
