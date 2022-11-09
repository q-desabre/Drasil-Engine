
#pragma once

#include <functional>
#include "Event.hpp"

namespace drasil
{
    struct NetworkComponent
    {
        std::function<void()> Create;
        std::function<void()> Update;
        std::function<void(Event& e)> OnUpdate;
        std::function<void()> Destroy;
    };
}