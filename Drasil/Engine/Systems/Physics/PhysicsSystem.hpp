#pragma once

#include "../ASystem.hpp"

namespace drasil
{
    class PhysicsSystem : public ASystem
    {
    public:
        void InitSignature();

        void Update(float dt);
    };
}
