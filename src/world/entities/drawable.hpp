#pragma once
#include "core/graphics.hpp"
#include "world/entity.hpp"
#include "world/entityclass.hpp"
#include "world/entities/component/position.hpp"

namespace World
{
    class DrawableEntityClass;

    class DrawableEntity : public Entity, virtual public Component::Position
    {
    public:
        using Entity::Entity;
        virtual void draw();
    };

    class DrawableEntityClass : public EntityClass
    {
    public:
        using EntityClass::EntityClass;
        int rotations;
        virtual void load();
        virtual void unload();
        virtual void draw(DrawableEntity* entity);
    private:
        std::vector<Graphics::Region*> regions;
    };
}
