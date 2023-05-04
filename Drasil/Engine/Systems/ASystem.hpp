#pragma once

#include <set>
#include "../../Common/Types/Types.hpp"

namespace drasil
{

    class ASystem
    {
    public:
        virtual void InitSignature() = 0;
        virtual void Update(float dt) = 0;
        std::set<Entity> mEntities;
    };
}