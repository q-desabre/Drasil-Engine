
#include "RenderSystem.hpp"
#include <filesystem>
#include <iostream>
#include "../../Components.hpp"
#include "../../Core.hpp"

using namespace drasil;

void RenderSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<RenderComponent>());
    signature.set(gCoordinator.GetComponentType<TransformComponent>());
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    gCoordinator.SetSystemSignature<RenderSystem>(signature);
}

void RenderSystem::UpdateMouseEvent()
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

void RenderSystem::UpdateKeyboardEvent()
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

void RenderSystem::ProcessEvents()
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

void RenderSystem::InitRender(const std::string& windowName,
                              const Vec2& windowSize,
                              const std::string& assetsPath)
{
    mWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);
    if (assetsPath.size() > 0)
    {
        InitRessources(assetsPath);
    }
}

void RenderSystem::Update(float dt)
{
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
            if (render.textString != "")
            {
                render.text.setPosition(transform.position.x,
                                        transform.position.y);
                mWindow.draw(render.text);
            }
            else if (render.texture != "")
            {
                render.sprite.setPosition(transform.position.x,
                                          transform.position.y);
                mWindow.draw(render.sprite);
            }
        }

        // auto& renderable = gCoordinator.GetComponent<Renderable>(entity);
        // mWindow.draw(renderable.mSprite);
    }
    mWindow.display();
}

void RenderSystem::InitRessources(const std::string& path)
{
    // iterator over file
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
                // remove 4 last character
                name.erase(name.size() - 4, 4);
                // std::cout << "Texture add " << name << " at " << entry.path()
                //           << std::endl;
                Textures.add(name, entry.path().string());
            }
            else if (entry.path().extension() == ".ttf")
            {
                name += entry.path().filename().string();
                // remove 4 last character
                name.erase(name.size() - 4, 4);
                std::cout << "Font add " << name << " at "
                          << entry.path().string() << std::endl;
                Fonts.add(name, entry.path().string());
            }  // ".wav"
            else if (entry.path().extension() == ".wav")
            {
                name += entry.path().filename().string();
                // remove 4 last character
                name.erase(name.size() - 4, 4);
                std::cout << "Sound add " << name << " at "
                          << entry.path().string() << std::endl;
                Sounds.add(name, entry.path().string());
            }
        }
    }
}