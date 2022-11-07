
#include "Drasil.hpp"
#include "TestScene.hpp"

int main()
{
    Drasil drasil("Drasil", {800, 600});
    
    drasil.PushLevel(std::make_shared<TestLevel>());

    drasil.Start();
}