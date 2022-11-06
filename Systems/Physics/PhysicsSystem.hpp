#pragma once

#include "System.hpp"

class PhysicsSystem : public System
{
public:
    void InitSignature();

    void Update(float dt);
};
