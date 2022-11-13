
#pragma once

// ENGINE
#include "Drasil/Components.hpp"
#include "Drasil/Core.hpp"
#include "Drasil/Game.hpp"
#include "Drasil/Systems.hpp"
#include "Drasil/Types.hpp"
// CUSTOM MADE
#include <iostream>
#include "Game/Parallax/Parallax.hpp"

class TestLevel : public drasil::Level
{
public:
    TestLevel() : b(*this, "Button", drasil::Vec3(200, 200, 0))
    {
        // AddEntity(p.GetID());
        AddEntity(b.GetID());
        // std::cout << (void*)typeid(drasil::StatusComponent).name() <<
        // std::endl;
        // gCoordinator.GetComponent<drasil::StatusComponent>(p.GetID());
        //   AddEntity(a.GetID());
    }

    ~TestLevel() {}

private:
    // drasil::Player p;
    drasil::Button b;
    // Parallax para;
};
