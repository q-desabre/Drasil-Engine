#pragma once

#include "System.hpp"
#include "Vec2.hpp"

// TODO add flag full screen etc

class IRenderSystem : public System
{
public:
    virtual void InitSignature() = 0;
    virtual void InitRender(const std::string& windowName,
                            const Vec2& windowSize) = 0;
    virtual void ProcessEvents() = 0;
    virtual void Update(float dt) = 0;
};
