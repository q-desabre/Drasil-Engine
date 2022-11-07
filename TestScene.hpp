
#pragma once

#include "Level.hpp"
#include "Player.hpp"

class TestLevel : public Level
{
public:
    TestLevel()
    {
        Player p;
        Actor a;

        AddEntity(p.GetID());
        AddEntity(a.GetID());
    }

    ~TestLevel() {}
};
