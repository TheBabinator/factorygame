#pragma once
#include <map>
#include "world/tile.hpp"
#include "content/tiles.hpp"

namespace World
{
    extern int chunkSize;

    class Map;

    class Chunk
    {
    private:
        Tile** tiles;
    public:
        int x;
        int y;
        Map* map;
        Chunk(int cx, int cy, Map* parentMap);
        ~Chunk();
        void draw();
    };

    class Map
    {
    private:
        std::map<std::pair<int, int>, Chunk*> chunks;
    public:
        Map();
        ~Map();
        void loadChunk(int cx, int cy);
        void update(int deltaTicks);
        void draw();
    };
}

#include "world/tile.hpp"
