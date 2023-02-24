#include "content/entities.hpp"

namespace Entities
{
    World::PlayerEntityClass *player;

    void addContent()
    {
        player = new World::PlayerEntityClass("player");
        player->rotations = 8;
    }

    void removeContent()
    {
        delete player;
    }
}
