
#include "NetworkSystem.hpp"
#include "Components.hpp"
#include "Coordinator.hpp"

void NetworkSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<Active>());
    signature.set(gCoordinator.GetComponentType<ReplicatedComponent>());
    gCoordinator.SetSystemSignature<NetworkSystem>(signature);
}

void NetworkSystem::Update(float dt)
{
    for (auto& entity : mEntities)
    {
        auto& active = gCoordinator.GetComponent<Active>(entity);
        if (active.active)
        {
            auto& replicated =
                gCoordinator.GetComponent<ReplicatedComponent>(entity);

            for (auto& component : replicated.components)
            {
                if (component == typeid(Transform))
                {
                    auto& transform =
                        gCoordinator.GetComponent<Transform>(entity);
                }
            }
        }
    }
}