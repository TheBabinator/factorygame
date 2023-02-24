#include "content/tiles.hpp"

namespace Tiles
{
    World::Ground *dirt, *grass, *squares;

    void addContent()
    {
        dirt = new World::Ground("dirt");
        dirt->variants = 4;

        grass = new World::Ground("grass");
        grass->variants = 4;

        squares = new World::Ground("squares");
        squares->variants = 4;
    }

    void removeContent()
    {
        delete dirt;
        delete grass;
        delete squares;
    }
};
