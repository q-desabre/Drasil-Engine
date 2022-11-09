
#pragma once

#include "Event.hpp"

namespace drasil
{
    class IReplicated
    {
        virtual void CreateNetwork() = 0;
        virtual void UpdateNetwork() = 0;
        virtual void OnUpdateNetwork(Event& event) = 0;
        virtual void DestroyNetwork() = 0;
    };
}