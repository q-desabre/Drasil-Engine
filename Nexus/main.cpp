#include "Drasil/Core.hpp"
#include "MyLevel.hpp"

int main()
{
    std::cout << "Nexus is starting..." << std::endl;

    drasil::Drasil drasil("SampleGame", drasil::Vec2(1920, 1080),
                          "../../Assets");

    std::cout << "Drasil initialized." << std::endl;
    drasil.PushLevel(std::make_shared<MyLevel>());
    drasil.Start();
}