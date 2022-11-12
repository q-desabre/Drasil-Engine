
#pragma once

#include "Drasil/Components.hpp"
#include "Drasil/Core.hpp"
#include "Drasil/Game.hpp"
#include "Drasil/Systems.hpp"
#include "Drasil/Types.hpp"

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
