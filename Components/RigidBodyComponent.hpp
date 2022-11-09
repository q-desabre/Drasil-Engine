#pragma once

#include "Vec3.hpp"

namespace drasil
{
    struct RigidBodyComponent
    {
        Vec3 velocity;
        Vec3 acceleration;
    };
}