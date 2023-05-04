#pragma once

#include "../../Core/System/System.hpp"

namespace drasil
{
    class PhysicsSystem : public System
    {
    public:
        void InitSignature();

        void Update(float dt);
    };
}
