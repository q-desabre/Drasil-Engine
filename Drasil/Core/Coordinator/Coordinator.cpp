
#include "Coordinator.hpp"
#include "../../Components.hpp"
#include "../../Systems.hpp"

using namespace drasil;

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
    mRenderSystem = RegisterSystem<RenderSystem>();
    mRenderSystem->InitRender(windowName, windowSize, assetsPath);
}
