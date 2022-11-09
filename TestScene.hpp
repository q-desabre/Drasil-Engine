
#pragma once

#include "Level.hpp"
#include "Player.hpp"

class TestLevel : public drasil::Level
{
public:
    TestLevel()
    {
        AddEntity(p.GetID());
        //   AddEntity(a.GetID());
    }

    ~TestLevel() {}

private:
    drasil::Player p;
};
