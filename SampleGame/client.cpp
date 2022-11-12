
#include "Drasil.hpp"
#include "EntityFactory.hpp"
#include "TestScene.hpp"

int main()
{
    drasil::Drasil drasil("Drasil", drasil::Vec2(1280, 720));

    EntityFactory::getInstance().Init();
    drasil.StartClient(54000);
    // drasil.PushLevel(std::make_shared<TestLevel>());

    // drasil.Start();
}