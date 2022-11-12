
#include <iostream>
#include "Drasil/Components.hpp"
#include "Drasil/Core.hpp"
#include "Drasil/Systems.hpp"
#include "Drasil/Types.hpp"
#include "TestScene.hpp"

int main()
{
    drasil::Drasil drasil("SampleGame", drasil::Vec2(1920, 1080),
                          "../../Assets");
    drasil.PushLevel(std::make_shared<TestLevel>());
    drasil.Start();
    // wait 2 seconde

    return (0);
}