#pragma once

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
    };
}

#define gCoordinator drasil::Coordinator::GetInstance()
#define GET_COMPONENT(entity, component) \
    gCoordinator.GetComponent<component>(entity)
