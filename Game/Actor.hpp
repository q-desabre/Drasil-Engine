
#pragma once

#include "Components.hpp"
#include "Coordinator.hpp"

class Actor
{
public:
    Actor();
    ~Actor();

    Entity GetID() const;

protected:
    Entity mID;
};