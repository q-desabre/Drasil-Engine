
#include "Drasil.hpp"
#include "TestScene.hpp"

int main()
{
    drasil::Drasil drasil;

    drasil.StartServer(54000);
    // wait to press enter
    std::cin.get();

    drasil.PushLevel(std::make_shared<TestLevel>());
    drasil.Start();

    // drasil.PushLevel(std::make_shared<TestLevel>());

    // drasil.Start();
}