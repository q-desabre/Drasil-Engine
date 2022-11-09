#pragma once

#include "Vec3.hpp"

namespace drasil
{
    struct TransformComponent
    {
        Vec3 position;
        Vec3 rotation;
        Vec3 scale;
    };
}