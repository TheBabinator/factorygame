#pragma once
#include "content/registry.hpp"

namespace World
{
    class EntityClass : public Registry::Content
    {
    public:
        using Registry::Content::Content;
    };
}
