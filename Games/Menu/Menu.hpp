
#pragma once

#include <memory>
#include "Drasil/Components.hpp"
#include "Drasil/Drasil.hpp"
#include "Drasil/Game.hpp"
#include "Drasil/Systems.hpp"
#include "Drasil/Types.hpp"

class Menu : public drasil::Level
{
public:
    Menu();

private:
    drasil::Sprite s;
    drasil::Text t;
};

extern "C" __declspec(dllexport) std::shared_ptr<drasil::Level> CreateLevel()
{
    return std::make_shared<Menu>();
}