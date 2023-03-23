#pragma once

#include "../../Drasil.hpp"

namespace drasil
{
    class PhysicsSystem : public System
    {
    public:
        void InitSignature();

        void Update(float dt);
    };
}
