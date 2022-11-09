#include "PhysicsSystem.hpp"

#include "Components.hpp"
#include "Coordinator.hpp"

using namespace drasil;

void PhysicsSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<GravityComponent>());
    signature.set(gCoordinator.GetComponentType<RigidBodyComponent>());
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
            auto& rigidBody =
                gCoordinator.GetComponent<RigidBodyComponent>(entity);
            auto& transform =
                gCoordinator.GetComponent<TransformComponent>(entity);
            // Forces
            auto const& gravity =
                gCoordinator.GetComponent<GravityComponent>(entity);

            rigidBody.velocity += rigidBody.acceleration * dt;
            transform.position += rigidBody.velocity * dt;
        }
    }
}
