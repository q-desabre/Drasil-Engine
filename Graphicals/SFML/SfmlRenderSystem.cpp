
#include "SfmlRenderSystem.hpp"
#include <filesystem>
#include <iostream>
#include "Drasil/Components.hpp"
#include "Drasil/Drasil.hpp"
#include "Drasil/Tools.hpp"

using namespace drasil;

void SfmlRenderSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<RenderComponent>());
    signature.set(gCoordinator.GetComponentType<TransformComponent>());
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    gCoordinator.SetSystemSignature<ARenderSystem>(signature);
}

void SfmlRenderSystem::UpdateMouseEvent()
{
    // check if mEvent is mouseMoved
    if (mEvent.type == sf::Event::MouseMoved)
    {
        mMouseEvent.action = MouseEvent::Action::MOVE;
        mMouseEvent.prevX = mMouseEvent.x;
        mMouseEvent.prevY = mMouseEvent.y;
        mMouseEvent.x = sf::Mouse::getPosition(mWindow).x;
        mMouseEvent.y = sf::Mouse::getPosition(mWindow).y;
        SendMouseEvent();
    }
    else if (mEvent.type == sf::Event::MouseButtonPressed)
    {
        mMouseEvent.action = (MouseEvent::Action)MouseEvent::Action::PRESS;
        mMouseEvent.button = (MouseEvent::Button)mEvent.mouseButton.button;
        SendMouseEvent();
    }
    else if (mEvent.type == sf::Event::MouseButtonReleased)
    {
        mMouseEvent.action = (MouseEvent::Action)MouseEvent::Action::RELEASE;
        mMouseEvent.button = (MouseEvent::Button)mEvent.mouseButton.button;
        SendMouseEvent();
    }
}

void SfmlRenderSystem::UpdateKeyboardEvent()
{
    if (mEvent.type == sf::Event::KeyPressed)
    {
        mKeyboardEvent.action =
            (KeyboardEvent::Action)KeyboardEvent::Action::PRESS;
        mKeyboardEvent.key = (KeyboardEvent::Key)mEvent.key.code;
        SendKeyboardEvent();
    }
    else if (mEvent.type == sf::Event::KeyReleased)
    {
        mKeyboardEvent.action =
            (KeyboardEvent::Action)KeyboardEvent::Action::RELEASE;
        mKeyboardEvent.key = (KeyboardEvent::Key)mEvent.key.code;
        SendKeyboardEvent();
    }
}

void SfmlRenderSystem::ProcessEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(mEvent))
    {
        // check Mouse Event
        UpdateMouseEvent();
        UpdateKeyboardEvent();
        if (mEvent.type == sf::Event::Closed)
        {
            gCoordinator.SendEvent(Events::Window::QUIT);
            mWindow.close();
            break;
        }
    }
}

void SfmlRenderSystem::InitRender(const std::string& windowName,
                                  const Vec2& windowSize,
                                  const std::string& assetsPath)
{
    mWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);
    if (assetsPath.size() > 0)
    {
        InitRessources(assetsPath);
        LogManager::Print(Events::Logs::Type::ENGINE, "Ressources initialized");
    }
}

void SfmlRenderSystem::Update(float dt)
{
    std::cout << "RenderSystem Update" << std::endl;
    std::cout << "Entities: " << mEntities.size() << std::endl;
    mWindow.clear();
    if (mEntities.size() == 0)
        return;
    for (auto entity : mEntities)
    {
        auto& status = gCoordinator.GetComponent<StatusComponent>(entity);

        if (status.active)
        {
            auto& transform =
                gCoordinator.GetComponent<TransformComponent>(entity);
            auto& render = gCoordinator.GetComponent<RenderComponent>(entity);
            if (render.meta.isModified)
            {
                if (render.meta.type == RenderType::TEXTURE)
                {
                    if (mSprites.find(entity) == mSprites.end())
                        mSprites[entity] = sf::Sprite();
                    mSprites[entity].setTexture(mTextures.get(
                        std::get<TextureComponent>(render.data).path));
                    mSprites[entity].setPosition(transform.position.x,
                                                 transform.position.y);
                    mSprites[entity].setScale(transform.scale.x,
                                              transform.scale.y);
                    // mSprites[entity].setRotation(transform.rotation);
                }
                else if (render.meta.type == RenderType::TEXT)
                {
                    if (mTexts.find(entity) == mTexts.end())
                        mTexts[entity] = sf::Text();
                    mTexts[entity].setString(
                        std::get<TextComponent>(render.data).string);
                    mTexts[entity].setFont(
                        mFonts.get(std::get<TextComponent>(render.data).font));
                    // mTexts[entity].setCharacterSize(
                    //     std::get<TextComponent>(render.data).size);
                    mTexts[entity].setPosition(transform.position.x,
                                               transform.position.y);
                    mTexts[entity].setScale(transform.scale.x,
                                            transform.scale.y);
                    // mTexts[entity].setRotation(transform.rotation);
                }
            }

            if (render.meta.type == RenderType::TEXTURE)
            {
                mWindow.draw(mSprites[entity]);
            }
            else if (render.meta.type == RenderType::TEXT)
            {
                mWindow.draw(mTexts[entity]);
            }
        }
    }
    mWindow.display();
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
            if (entry.path().extension() == ".png")
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