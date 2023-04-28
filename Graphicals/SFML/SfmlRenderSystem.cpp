
#include "SfmlRenderSystem.hpp"
#include <filesystem>
#include <iostream>
#include "Drasil/Components.hpp"
#include "Drasil/Drasil.hpp"
#include "Drasil/Utils.hpp"

using namespace drasil;

void SfmlRenderSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<RenderComponent>());
    signature.set(gCoordinator.GetComponentType<TransformComponent>());
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    gCoordinator.SetSystemSignature<ARenderSystem>(signature);
    BIND_EVENT("UpdateEntity", SfmlRenderSystem::UpdateEntity);
}

void SfmlRenderSystem::ProcessEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(mEvent))
    {
        UpdateMouseEvent();
        UpdateKeyboardEvent();

        if (mEvent.type == sf::Event::Resized)
        {
            float wRatio = mEvent.size.width / WINDOW_WIDTH;
            float hRatio = mEvent.size.height / WINDOW_HEIGHT;

            mWindowSize.y = mEvent.size.height;
            mWindowSize.x = mEvent.size.width;
        }
        if (mEvent.type == sf::Event::Closed)
        {
            Event e("quit");
            gCoordinator.SendEvent(e);
            mWindow.close();
            break;
        }
    }
}

void SfmlRenderSystem::InitRender(const std::string& windowName,
                                  const Vec2& windowSize,
                                  const std::string& assetsPath)
{
    mWindowName = windowName;
    mWindowSize = windowSize;
    mWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);
    if (assetsPath.size() > 0)
    {
        InitRessources(assetsPath);
        LogManager::Print(Events::Logs::Type::ENGINE, "Ressources initialized");
    }
}

void SfmlRenderSystem::Update(float dt)
{
    mWindow.clear();
    if (mEntities.size() == 0)
        return;
    for (auto entity : mEntities)
    {
        auto& status = gCoordinator.GetComponent<StatusComponent>(entity);
        if (status.active)
        {
            auto& render = gCoordinator.GetComponent<RenderComponent>(entity);
            if (render.meta.type == RenderType::TEXTURE)
                mWindow.draw(mSprites[entity]);
            else if (render.meta.type == RenderType::TEXT)
                mWindow.draw(mTexts[entity]);
        }
    }
    mWindow.display();
}

void SfmlRenderSystem::UpdateEntity(Event& event)
{
    auto entity = event.GetParam<Entity>("entity");
   
    auto& render = gCoordinator.GetComponent<RenderComponent>(entity);
    auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);
    if (render.meta.type == RenderType::TEXTURE)
        UpdateSprite(entity, transform, render);
    else if (render.meta.type == RenderType::TEXT)
        UpdateText(entity, transform, render);
}

void SfmlRenderSystem::UpdateText(Entity entity,
                                  TransformComponent& transform,
                                  RenderComponent& render)
{
    if (mTexts.find(entity) == mTexts.end())
        mTexts[entity] = sf::Text();
    mTexts[entity].setCharacterSize(TEXT_COMP.fontSize);
    mTexts[entity].setString(TEXT_COMP.string);
    mTexts[entity].setFont(mFonts.get(TEXT_COMP.font));

    mTexts[entity].setPosition(transform.position.x, transform.position.y);
    mTexts[entity].setScale(transform.scale.x, transform.scale.y);

    mTexts[entity].setOutlineThickness(TEXT_COMP.outlineThickness);
    mTexts[entity].setOutlineColor(
        sf::Color(TEXT_COMP.outlineColor.x, TEXT_COMP.outlineColor.y,
                  TEXT_COMP.outlineColor.z, TEXT_COMP.outlineColor.w));

    mTexts[entity].setFillColor(sf::Color(TEXT_COMP.color.x, TEXT_COMP.color.y,
                                          TEXT_COMP.color.z,
                                          TEXT_COMP.color.w));

    TEXT_COMP.size = Vec2{mTexts[entity].getLocalBounds().width,
                          mTexts[entity].getLocalBounds().height};
    // mTexts[entity].setRotation(transform.rotation);
}

void SfmlRenderSystem::UpdateSprite(Entity entity,
                                    TransformComponent& transform,
                                    RenderComponent& render)
{
    if (mSprites.find(entity) == mSprites.end())
        mSprites[entity] = sf::Sprite();

    mSprites[entity].setTexture(mTextures.get(TEXTURE_COMP.path));

    mSprites[entity].setPosition(transform.position.x, transform.position.y);
    mSprites[entity].setScale(transform.scale.x, transform.scale.y);
    // mSprites[entity].setRotation(transform.rotation);

    Vec2 v = Vec2(mSprites[entity].getLocalBounds().width,
                  mSprites[entity].getLocalBounds().height);
    TEXTURE_COMP.size = Vec2(mSprites[entity].getLocalBounds().width,
                             mSprites[entity].getLocalBounds().height);
}

void SfmlRenderSystem::SetWindowSize(const Vec2& size)
{
    mWindow.setSize(sf::Vector2u(size.x, size.y));
}

void SfmlRenderSystem::SetWindowName(const std::string& name)
{
    mWindow.setTitle(name);
    mWindowName = name;
}

void SfmlRenderSystem::SetWindowFullScreen(bool fullscreen)
{
    if (fullscreen)
        mWindow.create(sf::VideoMode(mWindowSize.x, mWindowSize.y), mWindowName,
                       sf::Style::Fullscreen);
    else
        mWindow.create(sf::VideoMode(mWindowSize.x, mWindowSize.y),
                       mWindowName);
}

void SfmlRenderSystem::UpdateMouseEvent()
{
    auto tmp = mMouseEvent;
    if (mEvent.type == sf::Event::MouseMoved)
    {
        mMouseEvent.action = MouseEvent::Action::MOVE;
        mMouseEvent.prevX = mMouseEvent.x;
        mMouseEvent.prevY = mMouseEvent.y;
        mMouseEvent.x = sf::Mouse::getPosition(mWindow).x;
        mMouseEvent.y = sf::Mouse::getPosition(mWindow).y;
    }
    else if (mEvent.type == sf::Event::MouseButtonPressed)
    {
        mMouseEvent.action = (MouseEvent::Action)MouseEvent::Action::PRESS;
        mMouseEvent.button = (MouseEvent::Button)mEvent.mouseButton.button;
    }
    else if (mEvent.type == sf::Event::MouseButtonReleased)
    {
        mMouseEvent.action = (MouseEvent::Action)MouseEvent::Action::RELEASE;
        mMouseEvent.button = (MouseEvent::Button)mEvent.mouseButton.button;
    }
    if (mMouseEvent.action != tmp.action || mMouseEvent.button != tmp.button ||
        mMouseEvent.prevX != tmp.prevX || mMouseEvent.prevY != tmp.prevY ||
        mMouseEvent.x != tmp.x || mMouseEvent.y != tmp.y)
    {
        SendMouseEvent();
    }
}

void SfmlRenderSystem::UpdateKeyboardEvent()
{
    auto tmp = mKeyboardEvent;
    if (mEvent.type == sf::Event::KeyPressed)
    {
        mKeyboardEvent.action =
            (KeyboardEvent::Action)KeyboardEvent::Action::PRESS;
        mKeyboardEvent.key = (KeyboardEvent::Key)mEvent.key.code;
    }
    else if (mEvent.type == sf::Event::KeyReleased)
    {
        mKeyboardEvent.action =
            (KeyboardEvent::Action)KeyboardEvent::Action::RELEASE;
        mKeyboardEvent.key = (KeyboardEvent::Key)mEvent.key.code;
    }
    if (mKeyboardEvent.action != tmp.action || mKeyboardEvent.key != tmp.key)
    {
        SendKeyboardEvent();
    }
}

const Vec2& SfmlRenderSystem::GetWindowSize() const
{
    return mWindowSize;
}

const std::string& SfmlRenderSystem::GetWindowName() const
{
    return mWindowName;
}

bool SfmlRenderSystem::IsWindowFullScreen() const
{
    return mWindow.getSize() == sf::Vector2u(mWindowSize.x, mWindowSize.y);
}

void SfmlRenderSystem::InitRessources(const std::string& path)
{
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_directory(entry.path()))
            InitRessources(entry.path().string());
        else
        {
            std::string name;
            if (entry.path().extension() == ".png" ||
                entry.path().extension() == ".jpg")
            {
                name += entry.path().parent_path().filename().string();
                name += "_";
                name += entry.path().filename().string();
                name.erase(name.size() - 4, 4);
                mTextures.add(name, entry.path().string());
            }
            else if (entry.path().extension() == ".ttf")
            {
                name += entry.path().filename().string();
                name.erase(name.size() - 4, 4);
                mFonts.add(name, entry.path().string());
            }  // ".wav"
            else if (entry.path().extension() == ".wav")
            {
                name += entry.path().filename().string();
                name.erase(name.size() - 4, 4);
                mSounds.add(name, entry.path().string());
            }
        }
    }
}
