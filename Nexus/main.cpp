#include "Drasil/Drasil.hpp"
#include "Drasil/Tools/DynamicLoader.hpp"
#include "MyLevel.hpp"

typedef std::shared_ptr<drasil::Level> (*CreateLevelFunc)(void);

int main()
{
    drasil::DynamicLoader dl;


    drasil::Core drasil("SampleGame", drasil::Vec2(1920, 1080), "../../Assets");

    dl.Open("libmenu.dll");
    auto f = dl.GetFunction<CreateLevelFunc>("CreateLevel");
    drasil.PushLevel(f());

    drasil.Start();
}