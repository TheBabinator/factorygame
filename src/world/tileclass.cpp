#include "world/tileclass.hpp"

namespace World
{
    void TileClass::load()
    {
        Registry::Content::load();
        std::string file = "assets/sprites/tile/" + name + ".png";
        std::cout << "loading file " << file << std::endl;
        Graphics::Sheet tileSheet = Graphics::Sheet(file);

        for (int i = 0; i < variants; i++)
        {
            regions.push_back(tileSheet.getRegionPointer(i * 32, 0, 32, 32));
        }
    }

    void TileClass::unload()
    {
        Registry::Content::unload();
        for (Graphics::Region* region : regions)
        {
            delete region;
        }
    }

    void TileClass::draw(Tile* tile)
    {
        Graphics::Rectangle rect = Graphics::Rectangle(tile->x, tile->y, 1, 1);
        rect = Graphics::project(rect);

        float hash = 0.39548639387;
        hash = hash + tile->x * 1.7876956856836521251;
        hash = hash * tile->x * 3.1184418488345422462;
        hash = hash + tile->y * 9.5345643563456230292;
        hash = hash * tile->y * 7.2487356873456786498;
        hash = hash - tile->x * 8.5469843598723458972;
        hash = hash - tile->y * 2.3984235985376498911;
        int index = fmod(hash, variants);
        if (index < 0) index *= -1;
        regions[index]->draw(rect);
    }
};
