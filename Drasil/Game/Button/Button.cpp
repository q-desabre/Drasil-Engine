
#include "Button.hpp"
#include "../../Tools.hpp"

using namespace drasil;

Button::Button()
{
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
    mSprite.SetTexture("Button_normal");
    mSpriteHover.SetTexture("Button_hover");
    mSpriteHover.SetActive(false);
    mSpritePressed.SetTexture("Button_pressed");
    mSpritePressed.SetActive(false);
    mSpriteDisabled.SetTexture("Button_disabled");
    mSpriteDisabled.SetActive(false);
    BIND_MOUSE(Button::Update);
}

Button::Button(Level& l, const std::string& texture, const Vec3& pos)
{
    gCoordinator.AddComponent(
        mID, TransformComponent{.position = Vec3(pos.x, pos.y, 0),
                                .rotation = Vec3(0, 0, 0),
                                .scale = Vec3(1, 1, 1)});
    mSprite.SetTexture(texture + "_normal");
    mSprite.SetPosition(pos);
    mSpriteHover.SetTexture(texture + "_hover");
    mSpriteHover.SetPosition(pos);
    mSpriteHover.SetActive(false);
    mSpritePressed.SetTexture(texture + "_pressed");
    mSpritePressed.SetPosition(pos);
    mSpritePressed.SetActive(false);
    mSpriteDisabled.SetTexture(texture + "_disabled");
    mSpriteDisabled.SetPosition(pos);
    mSpriteDisabled.SetActive(false);
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

#include <iostream>

void Button::Update(Event& event)
{
    auto data = event.GetParam<MouseEvent>(Events::Input::MOUSE_DATA);
    int x = data.x;
    int y = data.y;

    if (x >= mSprite.GetPosition().x &&
        x <= mSprite.GetPosition().x + mSprite.GetSize().x &&
        y >= mSprite.GetPosition().y &&
        y <= mSprite.GetPosition().y + mSprite.GetSize().y)
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