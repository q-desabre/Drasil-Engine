
#pragma once

#include <functional>
#include "../../Common/Types/Types.hpp"
#include "../../Engine/Level/Level.hpp"
#include "../Sprite/Sprite.hpp"

namespace drasil
{
    class Button : public Pawn
    {
        enum class State
        {
            NORMAL,
            HOVER,
            PRESSED,
            DISABLED
        };

    public:
        Button();
        Button(Level& l, const std::string& texture, const Vec3& pos);

        void SetOnClick(std::function<void()> onClick);

        void Update(Event& event);

        void SetPosition(const Vec3& pos) override;
        void SetPosition(float x, float y, float z = 0) override;

        void SetTexture(const std::string& texture);

        const Vec3& GetPosition() const override;
        const Vec2& GetSize() const;

    private:
        void InitSprites(const std::string& texture, const Vec3& pos);
        void InitSprite(State s, const std::string& texture, const Vec3& pos);

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
