#include "world/entity.hpp"

namespace World
{
    Entity::Entity(int id, EntityClass* entityClass)
    {
        this->id = id;
        this->entityClass = entityClass;
        age = 0;
    }

    void Entity::update(int deltaTicks)
    {
        age += deltaTicks;
    }

    void Entity::draw()
    {

    }
}
