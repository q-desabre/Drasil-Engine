
#pragma once

#include <functional>
#include "../Sprite/Sprite.hpp"

namespace drasil
{
    class Button : public Actor
    {
    public:
        Button();
        Button(Level& l, const std::string& texture, const Vec3& pos);

        void SetOnClick(std::function<void()> onClick);

        void Update(Event& event);

    private:
        Sprite mSprite;
        Sprite mSpriteHover;
        Sprite mSpritePressed;
        Sprite mSpriteDisabled;

        bool mIsHovered = false;
        bool mIsPressed = false;
        bool mIsDisabled = false;

        std::function<void()> mOnClick;
    };

}  // namespace drasil
