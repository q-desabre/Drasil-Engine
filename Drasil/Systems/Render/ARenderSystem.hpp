#pragma once

#include "../../Core/System/System.hpp"

// TODO add flag full screen etc
namespace drasil
{
    class ARenderSystem : public System
    {
    public:
        virtual void InitSignature() = 0;
        virtual void InitRender(const std::string& windowName,
                                const Vec2& windowSize,
                                const std::string& assetPath) = 0;
        virtual void ProcessEvents() = 0;
        virtual void Update(float dt) = 0;

        virtual void UpdateMouseEvent() = 0;
        virtual void UpdateKeyboardEvent() = 0;

        virtual void SendKeyboardEvent();
        virtual void SendMouseEvent();

    protected:
        MouseEvent mMouseEvent;
        KeyboardEvent mKeyboardEvent;
    };
}