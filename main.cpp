#include <chrono>
#include <iostream>
#include <random>
#include "Components.hpp"
#include "Coordinator.hpp"
#include "Systems.hpp"

#include "Player.hpp"

static bool quit = false;

void QuitHandler(Event& event)
{
    quit = true;
}

/*
    add to SceneSystem Coordinator
*/

int main()
{
    gCoordinator.Init("ECS", Vec2{800, 600});
    Player p;

    gCoordinator.AddEventListener(
        FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));

    float dt = 0.0f;

    while (!quit)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        gCoordinator.UpdateSystems(dt);

        auto stopTime = std::chrono::high_resolution_clock::now();

        dt = std::chrono::duration<float, std::chrono::seconds::period>(
                 stopTime - startTime)
                 .count();
    }
}