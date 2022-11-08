
#include "Drasil.hpp"
#include "TestScene.hpp"

int main()
{
    try
    {
        std::cout << "Starting Drasil..." << std::endl;
        Drasil drasil;
        std::cout << "Starting Server... " << std::endl;
        drasil.StartServer(54000);
        // drasil.Start();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // drasil.PushLevel(std::make_shared<TestLevel>());

    // drasil.Start();
}