#pragma once
#include "world/entities/drawable.hpp"
#include "world/entities/component/velocity.hpp"

namespace World
{
    class PlayerEntity : public DrawableEntity, virtual public Component::Velocity
    {
    public:
        using DrawableEntity::DrawableEntity;
        void update(int deltaTicks);
    };

    class PlayerEntityClass : public DrawableEntityClass
    {
    public:
        using DrawableEntityClass::DrawableEntityClass;
    };
}
