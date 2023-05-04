#include "PhysicsSystem.hpp"
#include "../../Components/Components.hpp"
#include "../../Core/Coordinator/Coordinator.hpp"

using namespace drasil;

void PhysicsSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<MovementComponent>());
    signature.set(gCoordinator.GetComponentType<TransformComponent>());
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
}

void PhysicsSystem::Update(float dt)
{
    // std::cout << "PhysicsSystem::Update" << std::endl;
    //  print nb of entities
    // std::cout << "Nb of entities: " << mEntities.size() << std::endl;
    if (mEntities.size() == 0)
        return;

    for (auto const& entity : mEntities)
    {
        auto& status = gCoordinator.GetComponent<StatusComponent>(entity);

        if (status.active)
        {
            auto& Movement =
                gCoordinator.GetComponent<MovementComponent>(entity);
            auto& transform =
                gCoordinator.GetComponent<TransformComponent>(entity);

            Movement.velocity += Movement.acceleration * dt;
            transform.position += Movement.velocity * dt;
        }
    }
}
