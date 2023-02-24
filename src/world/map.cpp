#include "world/map.hpp"

namespace World
{
    int chunkSize = 32;

    Chunk::Chunk(int cx, int cy, Map* parentMap)
    {
        std::cout << "new chunk" << std::endl;
        x = cx;
        y = cy;
        map = parentMap;
        Tile** tiles = new Tile*[chunkSize * chunkSize];
        for (int ty = 0; ty < chunkSize; ty++)
        {
            for (int tx = 0; tx < chunkSize; tx++)
            {
                Tile* tile = new Tile(tx, ty, this);
                tile->ground = Tiles::squares;
                tiles[ty * chunkSize + tx] = tile;
            }
        }
        this->tiles = tiles;
    }

    Chunk::~Chunk()
    {
        std::cout << "delete chunk" << std::endl;
        for (int ty = 0; ty < chunkSize; ty++)
        {
            for (int tx = 0; tx < chunkSize; tx++)
            {
                delete tiles[ty * chunkSize + tx];
            }
        }
        delete tiles;
    }

    void Chunk::draw()
    {
        for (int ty = 0; ty < chunkSize; ty++)
        {
            for (int tx = 0; tx < chunkSize; tx++)
            {
                Tile* tile = tiles[ty * chunkSize + tx];
                tile->draw();
            }
        }
    }

    Map::Map()
    {
        //loadChunk(0, 0);

        for (int cy = -1; cy <= 1; cy++)
        {
            for (int cx = -1; cx <= 1; cx++)
            {
                loadChunk(cx, cy);
            }
        }
    }

    Map::~Map()
    {
        for (std::pair<std::pair<int, int>, Chunk*> pair : chunks)
        {
            delete pair.second;
        }
    }

    void Map::loadChunk(int cx, int cy)
    {
        std::pair<int, int> pair = std::pair<int, int>(cx, cy);
        if (!chunks[pair])
        {
            chunks[pair] = new Chunk(cx, cy, this);
        }
    }

    void Map::update(int deltaTicks)
    {

    }

    void Map::draw()
    {
        for (std::pair<std::pair<int, int>, Chunk*> pair : chunks)
        {
            pair.second->draw();
        }
    }
}
