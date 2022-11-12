#pragma once

#include <set>
#include "../../Types.hpp"

namespace drasil
{

    class System
    {
    public:
        virtual void InitSignature() = 0;
        virtual void Update(float dt) = 0;
        std::set<Entity> mEntities;
    };
}