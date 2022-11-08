#include "PhysicsSystem.hpp"

#include "Components.hpp"
#include "Coordinator.hpp"

void PhysicsSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<Gravity>());
    signature.set(gCoordinator.GetComponentType<RigidBody>());
    signature.set(gCoordinator.GetComponentType<Transform>());
    signature.set(gCoordinator.GetComponentType<Active>());
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
        auto& active = gCoordinator.GetComponent<Active>(entity);

        if (active.status)
        {
            std::cout << "There is an active entity" << std::endl;
            auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
            auto& transform = gCoordinator.GetComponent<Transform>(entity);
            // Forces
            auto const& gravity = gCoordinator.GetComponent<Gravity>(entity);

            rigidBody.velocity += rigidBody.acceleration * dt;
            transform.position += rigidBody.velocity * dt;
        }
    }
}
