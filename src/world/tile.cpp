#include "world/tile.hpp"

namespace World
{
    Tile::Tile(int tx, int ty, Chunk* parentChunk)
    {
        x = tx;
        y = ty;
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
