#include "PlayerControlSystem.hpp"

#include "Components.hpp"
#include "Coordinator.hpp"

void PlayerControlSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<Player>());
    signature.set(gCoordinator.GetComponentType<Transform>());
    gCoordinator.SetSystemSignature<PlayerControlSystem>(signature);

    gCoordinator.AddEventListener(METHOD_LISTENER(
        Events::Window::INPUT, PlayerControlSystem::InputListener));
}

void PlayerControlSystem::Update(float dt)
{
    // for (auto& entity : mEntities)
    //{
    //	auto& transform = gCoordinator.Get<Transform>(entity);

    //	if (mButtons.test(static_cast<std::size_t>(InputButtons::W)))
    //	{
    //		transform.position.z += (dt * 10.0f);
    //	}

    //	else if (mButtons.test(static_cast<std::size_t>(InputButtons::S)))
    //	{
    //		transform.position.z -= (dt * 10.0f);
    //	}

    //	if (mButtons.test(static_cast<std::size_t>(InputButtons::Q)))
    //	{
    //		transform.position.y += (dt * 10.0f);
    //	}

    //	else if (mButtons.test(static_cast<std::size_t>(InputButtons::E)))
    //	{
    //		transform.position.y -= (dt * 10.0f);
    //	}

    //	if (mButtons.test(static_cast<std::size_t>(InputButtons::A)))
    //	{
    //		transform.position.x += (dt * 10.0f);
    //	}

    //	else if (mButtons.test(static_cast<std::size_t>(InputButtons::D)))
    //	{
    //		transform.position.x -= (dt * 10.0f);
    //	}
    //}
}

#include <iostream>

void PlayerControlSystem::InputListener(Event& event)
{
    mButtons = event.GetParam<int>(Events::Window::Input::INPUT);
    std::cout << "InputListener" << std::endl;
    std::cout << mButtons << std::endl;
}
