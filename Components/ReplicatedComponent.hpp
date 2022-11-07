
#pragma once

#include <typeinfo>
#include <vector>

struct ReplicatedComponent
{
    std::vector<std::type_info> types;
}