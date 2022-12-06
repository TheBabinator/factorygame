#pragma once
#include <map>
#include "world/tile.hpp"

namespace World
{
    extern int chunkSize;

    class Map;

    class Chunk
    {
    public:
        int x;
        int y;
        Chunk(int cx, int cy, Map* parentMap);
        ~Chunk();
        Map* map;
        Tile** tiles;
    };

    class Map
    {
    public:
        Map();
        ~Map();
        void loadChunk(int cx, int cy);
        void draw();
        std::map<std::pair<int, int>, Chunk*> chunks;
    };
}

#include "world/tile.hpp"
