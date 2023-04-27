#pragma once

#include "../../Utils/DynamicLoader.hpp"
#include "BaseCoordinator.hpp"

namespace drasil
{
    class Coordinator : public BaseCoordinator
    {
    protected:
        Coordinator() {}

    public:
        static Coordinator& GetInstance();

        void Init(const std::string& windowName,
                  const Vec2& windowSize,
                  const std::string& assetsPath);

    private:
        DynamicLoader mDynamicLoader;
    };
}

#define gCoordinator drasil::Coordinator::GetInstance()
#define GET_COMPONENT(entity, component) \
    gCoordinator.GetComponent<component>(entity)

// Quality of life macros
#define RENDER_SYSTEM gCoordinator.GetRenderSystem()
#define WINDOW_SIZE RENDER_SYSTEM->GetWindowSize()
#define WINDOW_WIDTH WINDOW_SIZE.x
#define WINDOW_HEIGHT WINDOW_SIZE.y
#define WINDOW_NAME RENDER_SYSTEM->GetWindowName()
#define WINDOW_FULLSCREEN RENDER_SYSTEM->IsWindowFullScreen()