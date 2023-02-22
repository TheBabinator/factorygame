#include "world/tile.hpp"

namespace World
{
    Tile::Tile(int tx, int ty, Chunk* parentChunk)
    {
        this->tx = tx;
        this->ty = ty;
        x = parentChunk->x * chunkSize + tx;
        y = parentChunk->y * chunkSize + ty;
        chunk = parentChunk;
    }

    Tile::~Tile()
    {

    }

    void Tile::draw()
    {
        ground->draw(this);
    }
}
