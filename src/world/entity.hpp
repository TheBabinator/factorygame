#pragma once
#include "world/entityclass.hpp"

namespace World
{
    class Entity
    {
    public:
        Entity(int id, EntityClass* entityClass);
        EntityClass* entityClass;
        int id;
        int age;
        virtual void update(int deltaTicks);
        virtual void draw();
    };
}
