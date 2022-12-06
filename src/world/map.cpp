#include "world/map.hpp"

namespace World
{
    int chunkSize = 32;

    Chunk::Chunk(int cx, int cy, Map* parentMap)
    {
        std::cout << "new chunk";
        x = cx;
        y = cy;
        map = parentMap;
        Tile** tiles = new Tile*[chunkSize * chunkSize];
        for (int tx = 0; tx < chunkSize; tx++)
        {
            for (int ty = 0; ty < chunkSize; ty++)
            {
                tiles[x * chunkSize + y] = new Tile(tx, ty, this);
            }
        }
        this->tiles = tiles;
    }

    Chunk::~Chunk()
    {
        std::cout << "delete chunk";
        for (int x = 0; x < chunkSize; x++)
        {
            for (int y = 0; y < chunkSize; y++)
            {
                delete tiles[x * chunkSize + y];
            }
        }
        delete tiles;
    }

    Map::Map()
    {
        loadChunk(0, 0);
    }

    Map::~Map()
    {

    }

    void Map::loadChunk(int cx, int cy)
    {
        std::pair<int, int> pair = std::pair<int, int>(cx, cy);
        if (!chunks[pair])
        {
            chunks[pair] = new Chunk(cx, cy, this);
        }
    }

    void Map::draw()
    {

    }
}
