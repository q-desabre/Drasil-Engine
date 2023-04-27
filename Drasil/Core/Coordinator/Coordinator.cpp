
#include "Coordinator.hpp"
#include "../../Components.hpp"
#include "../../Systems.hpp"
#include "../../Utils.hpp"

using namespace drasil;

typedef std::shared_ptr<ARenderSystem> (*CreateRenderSystemFunc)();

Coordinator& Coordinator::GetInstance()
{
    static Coordinator instance;
    return instance;
}

void Coordinator::Init(const std::string& windowName,
                       const Vec2& windowSize,
                       const std::string& assetsPath)
{
    RegisterComponents();
    RegisterSystems();

    mDynamicLoader.Open("./Graphicals/libsfmlRender.dll");
    auto f = mDynamicLoader.GetFunction<CreateRenderSystemFunc>(
        "CreateRenderSystem");
    mRenderSystem = f();
    mSystemManager->RegisterSystemManual(mRenderSystem);
    mRenderSystem->InitSignature();
    mRenderSystem->InitRender(windowName, windowSize, assetsPath);

        LogManager::Print(Events::Logs::Type::ENGINE, "Coordinator initialized");
}
