#pragma once

namespace World
{
    class TileClass;
    class Chunk;

    class Tile
    {
    public:
        int x;
        int y;
        Chunk* chunk;
        TileClass* ground;
        Tile(int tx, int ty, Chunk* parentChunk);
        ~Tile();
        void draw();
    private:
        int tx;
        int ty;
    };
}

#include "world/tileclass.hpp"
#include "world/map.hpp"
