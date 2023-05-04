
#pragma once

#include "../Types/Event.hpp"

namespace drasil
{
    class IReplicable
    {
        virtual void CreateNetwork() = 0;
        virtual void UpdateNetwork() = 0;
        virtual void OnUpdateNetwork(Event& event) = 0;
        virtual void DestroyNetwork() = 0;
    };
}