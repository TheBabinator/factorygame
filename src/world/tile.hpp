#pragma once

namespace World
{
    class TileClass;
    class Chunk;

    class Tile
    {
    public:
        Tile(int tx, int ty, Chunk* parentChunk);
        ~Tile();
        void draw();
        int x;
        int y;
        Chunk* chunk;
        TileClass* ground;
    };
}

#include "world/tileclass.hpp"
#include "world/map.hpp"
