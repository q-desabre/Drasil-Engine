
#pragma once

#include <functional>

namespace drasil
{
    class Event;

    struct NetworkComponent
    {
        std::function<void()> Create;
        std::function<void()> Update;
        std::function<void(Event& e)> OnUpdate;
        std::function<void()> Destroy;
    };
}