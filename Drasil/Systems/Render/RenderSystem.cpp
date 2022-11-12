
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

void RenderSystem::ProcessEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            gCoordinator.SendEvent(Events::Window::QUIT);
            mWindow.close();
            break;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                std::cout << "Enter pressed" << std::endl;
                Event event(Events::Window::INPUT);
                event.SetParam(Events::Window::Input::INPUT, 14);
                gCoordinator.SendEvent(event);
            }
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
            render.sprite.setPosition(transform.position.x,
                                      transform.position.y);
            mWindow.draw(render.sprite);
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