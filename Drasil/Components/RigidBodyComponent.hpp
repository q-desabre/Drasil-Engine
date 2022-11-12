#pragma once

#include "../Types.hpp"

namespace drasil
{
    struct RigidBodyComponent
    {
        Vec3 velocity;
        Vec3 acceleration;
    };
}