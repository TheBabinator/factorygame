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
        int hash = tile->x * 1735 + tile->y * 8392;
        hash = hash * 2938457;
        hash = hash % 8972345;
        hash = hash / 2435861;
        hash = hash % 2543609;
        if (hash < 0) hash *= -1;
        regions[hash % variants]->draw(tile->x * 32, tile->y * 32);
    }
};
