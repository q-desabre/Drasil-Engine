
#pragma once

#include "Components.hpp"
#include "Coordinator.hpp"

namespace drasil
{
    class Actor
    {
    public:
        Actor();
        ~Actor();

        Entity GetID() const;

    protected:
        Entity mID;
    };
}