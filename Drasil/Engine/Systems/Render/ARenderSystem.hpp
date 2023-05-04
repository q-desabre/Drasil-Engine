#pragma once

#include <string>
#include "../../Common/Types/Types.hpp"
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

        virtual void SetWindowSize(const Vec2& windowSize) = 0;
        virtual void SetWindowName(const std::string& windowName) = 0;
        virtual void SetWindowFullScreen(bool isFullScreen) = 0;
        virtual const Vec2& GetWindowSize() const = 0;
        virtual const std::string& GetWindowName() const = 0;
        virtual bool IsWindowFullScreen() const = 0;

        virtual void SendKeyboardEvent();
        virtual void SendMouseEvent();

    protected:
        MouseEvent mMouseEvent;
        KeyboardEvent mKeyboardEvent;
    };
}