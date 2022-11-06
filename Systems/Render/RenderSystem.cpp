
#include "RenderSystem.hpp"
#include <iostream>
#include "Coordinator.hpp"

void RenderSystem::InitSignature()
{
    // gCoordinator.SetSignature<Renderable>(mID);
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
                              const Vec2& windowSize)
{
    mWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowName);
}

void RenderSystem::Update(float dt)
{
    mWindow.clear();
    for (auto entity : mEntities)
    {
        // auto& renderable = gCoordinator.GetComponent<Renderable>(entity);
        // mWindow.draw(renderable.mSprite);
    }
    mWindow.display();
}