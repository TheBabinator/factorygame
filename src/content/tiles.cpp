#include "content/tiles.hpp"

namespace Tiles
{
    World::Ground *dirt, *grass;

    void addContent()
    {
        dirt = new World::Ground("dirt");
        dirt->variants = 4;

        grass = new World::Ground("grass");
        grass->variants = 4;
    }

    void removeContent()
    {
        delete dirt;
        delete grass;
    }
};
