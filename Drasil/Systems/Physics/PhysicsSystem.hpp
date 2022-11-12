#pragma once

#include "../../Core.hpp"

namespace drasil
{
    class PhysicsSystem : public System
    {
    public:
        void InitSignature();

        void Update(float dt);
    };
}
