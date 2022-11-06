
#pragma once

#include "Actor.hpp"

class Player : public Actor
{
public:
    Player() { gCoordinator.AddComponent(mID, Player{}); }
    ~Player() {}
};
