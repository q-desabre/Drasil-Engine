
#pragma once

#include <functional>
#include "Event.hpp"

struct NetworkComponent
{
    std::function<void(Event&)> create;
    std::function<void(Event&)> update;
    std::function<void(Event&)> destroy;
};