#pragma once
#include <ctime>
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
        Map* map;
        Tile** tiles;
    public:
        int x;
        int y;
        Chunk(int cx, int cy, Map* parentMap);
        ~Chunk();
        void draw();
    };

    class Map
    {
    private:
        std::map<std::pair<int, int>, Chunk*> chunks;
        float cameraX = 0;
        float cameraY = 0;
        float cameraScale = 1;
    public:
        Map();
        ~Map();
        void loadChunk(int cx, int cy);
        void update();
        void draw();
    };
}

#include "world/tile.hpp"
