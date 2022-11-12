
#pragma once

#include "Components.hpp"
#include "Core.hpp"
#include "Game.hpp"
#include "Systems.hpp"
#include "Types.hpp"

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
