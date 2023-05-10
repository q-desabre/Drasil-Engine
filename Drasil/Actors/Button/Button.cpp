
#include "Button.hpp"
#include <iostream>
#include "../../Engine/Coordinator/Coordinator.hpp"

using namespace drasil;

Button::Button()
{
    InitSprites("Button", Vec3(0, 0, 0));
    mIsPressed = false;
    mIsHovered = false;
    mSprite.SetActive(!mIsHovered && !mIsPressed && !mIsDisabled);
    mSpriteHover.SetActive(mIsHovered && !mIsPressed && !mIsDisabled);
    mSpritePressed.SetActive(!mIsHovered && mIsPressed && !mIsDisabled);
    mSpriteDisabled.SetActive(mIsDisabled);
    BIND_MOUSE(Button::Update);
}

Button::Button(Level& l, const std::string& texture, const Vec3& pos)
{
    InitSprites(texture, pos);
    l.AddEntity(mSprite.GetID());
    l.AddEntity(mSpriteHover.GetID());
    l.AddEntity(mSpritePressed.GetID());
    l.AddEntity(mSpriteDisabled.GetID());
    BIND_MOUSE(Button::Update);
}

void Button::SetOnClick(std::function<void()> onClick)
{
    mOnClick = onClick;
}

void Button::Update(Event& event)
{
    auto data = event.GetParam<MouseEvent>("data");
    int x = data.x;
    int y = data.y;

    if (x >= mSprite.GetPosition().x &&
        x <= mSprite.GetPosition().x +
                 mSprite.GetSize().x * mSprite.GetScale().x &&
        y >= mSprite.GetPosition().y &&
        y <= mSprite.GetPosition().y +
                 mSprite.GetSize().y * mSprite.GetScale().y)
    {
        if (data.action == MouseEvent::Action::PRESS &&
            data.button == MouseEvent::Button::LEFT)
        {
            std::cout << "click" << std::endl;
            mIsHovered = false;
            mIsPressed = true;
            // mOnClick();
        }
        else
        {
            mIsHovered = true;
            mIsPressed = false;
        }
    }
    else
    {
        mIsPressed = false;
        mIsHovered = false;
    }
    mSprite.SetActive(!mIsHovered && !mIsPressed && !mIsDisabled);
    mSpriteHover.SetActive(mIsHovered && !mIsPressed && !mIsDisabled);
    mSpritePressed.SetActive(!mIsHovered && mIsPressed && !mIsDisabled);
    mSpriteDisabled.SetActive(mIsDisabled);
}

void Button::InitSprites(const std::string& texture, const Vec3& pos)
{
    InitSprite(State::NORMAL, texture, pos);
    InitSprite(State::HOVER, texture, pos);
    InitSprite(State::PRESSED, texture, pos);
    InitSprite(State::DISABLED, texture, pos);
}

void Button::InitSprite(State state,
                        const std::string& texture,
                        const Vec3& pos)
{
    switch (state)
    {
    case State::NORMAL:
        mSprite.SetTexture(texture + "_normal");
        mSprite.SetPosition(pos);
        mSprite.SetActive(true);
        break;
    case State::HOVER:
        mSpriteHover.SetTexture(texture + "_hover");
        mSpriteHover.SetPosition(pos);
        mSpriteHover.SetActive(false);
        break;
    case State::PRESSED:
        mSpritePressed.SetTexture(texture + "_pressed");
        mSpritePressed.SetPosition(pos);
        mSpritePressed.SetActive(false);
        break;
    case State::DISABLED:
        mSpriteDisabled.SetTexture(texture + "_disabled");
        mSpriteDisabled.SetPosition(pos);
        mSpriteDisabled.SetActive(false);
        break;
    }
}

void Button::SetPosition(const Vec3& pos)
{
    mSprite.SetPosition(pos);
    mSpriteHover.SetPosition(pos);
    mSpritePressed.SetPosition(pos);
    mSpriteDisabled.SetPosition(pos);
}

void Button::SetPosition(float x, float y, float z)
{
    mSprite.SetPosition(x, y, z);
    mSpriteHover.SetPosition(x, y, z);
    mSpritePressed.SetPosition(x, y, z);
    mSpriteDisabled.SetPosition(x, y, z);
}

const Vec3& Button::GetPosition() const
{
    return mSprite.GetPosition();
}

const Vec2& Button::GetSize() const
{
    return mSprite.GetSize();
}