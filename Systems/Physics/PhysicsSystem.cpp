#include "PhysicsSystem.hpp"

#include "Components.hpp"
#include "Coordinator.hpp"

void PhysicsSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<Gravity>());
    signature.set(gCoordinator.GetComponentType<RigidBody>());
    signature.set(gCoordinator.GetComponentType<Transform>());
    gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
}

void PhysicsSystem::Update(float dt)
{
    for (auto const& entity : mEntities)
    {
        auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
        auto& transform = gCoordinator.GetComponent<Transform>(entity);

        // Forces
        auto const& gravity = gCoordinator.GetComponent<Gravity>(entity);

        transform.position += rigidBody.velocity * dt;

        rigidBody.velocity += gravity.force * dt;
    }
}
