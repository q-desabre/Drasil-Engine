#pragma once

#include "../../Core.hpp"
#include "../../Tools.hpp"

// TODO add flag full screen etc
namespace drasil
{

    class IRenderSystem : public System
    {
    public:
        virtual void InitSignature() = 0;
        virtual void InitRender(const std::string& windowName,
                                const Vec2& windowSize,
                                const std::string& assetPath) = 0;
        virtual void ProcessEvents() = 0;
        virtual void Update(float dt) = 0;
    };
}