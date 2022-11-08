
#include "Drasil.hpp"
#include "TestScene.hpp"

int main()
{
    Drasil drasil("Drasil", Vec2(1280, 720));

    drasil.StartClient(54000);
    // drasil.PushLevel(std::make_shared<TestLevel>());

    // drasil.Start();
}