#include "Drasil/Common/DynamicLoader.hpp"
#include "Drasil/Drasil.hpp"

typedef std::shared_ptr<drasil::Level> (*CreateLevelFunc)(void);

int main()
{
    drasil::Core core("SampleGame", drasil::Vec2(1920, 1080), "../../Assets");
    drasil::DynamicLoader dl;

    dl.Open("libmenu.dll");
    auto f = dl.GetFunction<CreateLevelFunc>("CreateLevel");
    core.PushLevel(f());

    core.Start();
}