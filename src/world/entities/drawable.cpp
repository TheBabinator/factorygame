#include "world/entities/drawable.hpp"

namespace World
{
    void DrawableEntity::draw()
    {
        ((DrawableEntityClass*)entityClass)->draw(this);
    }

    void DrawableEntityClass::load()
    {
        Registry::Content::load();
        std::string file = "assets/sprites/entity/" + name + ".png";
        std::cout << "loading file " << file << std::endl;
        Graphics::Sheet spriteSheet = Graphics::Sheet(file);

        for (int i = 0; i < rotations; i++)
        {
            regions.push_back(spriteSheet.getRegionPointer(i * 32, 0, 32, 32));
        }
    }

    void DrawableEntityClass::unload()
    {
        Registry::Content::unload();
        for (Graphics::Region* region : regions)
        {
            delete region;
        }
    }

    void DrawableEntityClass::draw(DrawableEntity* entity)
    {
        Graphics::Rectanglef rect = Graphics::Rectanglef(entity->x, entity->y, 1, 1);
        Graphics::Rectangle projected = Graphics::project(rect);

        int index = (entity->rotation / PI / 2) * rotations + 0.5;
        index = index % rotations;
        if (index < 0) index *= -1;

        regions[index]->draw(projected);
    }
}
