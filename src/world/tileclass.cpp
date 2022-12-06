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
        regions[0]->draw();
    }
};
