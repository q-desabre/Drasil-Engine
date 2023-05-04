
#include "BaseCoordinator.hpp"

using namespace drasil;

BaseCoordinator::BaseCoordinator()
{
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mSystemManager = std::make_unique<SystemManager>();
}

// TO REMOVE
void BaseCoordinator::StartServer(unsigned short port)
{
    mNetworkSystem = RegisterSystem<NetworkSystem>();
    mNetworkSystem->StartServer(port);
}

void BaseCoordinator::StartClient(unsigned short port)
{
    mNetworkSystem = RegisterSystem<NetworkSystem>();
    mNetworkSystem->StartClient(port);
}

void BaseCoordinator::RegisterComponents()
{
    RegisterComponent<GravityComponent>();
    RegisterComponent<StatusComponent>();
    RegisterComponent<MovementComponent>();
    RegisterComponent<TransformComponent>();
    RegisterComponent<InputComponent>();
    RegisterComponent<RenderComponent>();
    RegisterComponent<NetworkComponent>();
}

void BaseCoordinator::RegisterSystems()
{
    RegisterSystem<PhysicsSystem>();
    RegisterSystem<PlayerControlSystem>();
}

void BaseCoordinator::UpdateSystems(float dt)
{
    if (mRenderSystem != nullptr)
        mRenderSystem->ProcessEvents();

    mSystemManager->UpdateSystems(dt);

    if (mRenderSystem != nullptr)
    {
        mRenderSystem->Update(dt);
    }
}

Entity BaseCoordinator::CreateEntity()
{
    return mEntityManager->CreateEntity();
}

void BaseCoordinator::DestroyEntity(Entity entity)
{
    mEntityManager->DestroyEntity(entity);

    mComponentManager->EntityDestroyed(entity);

    mSystemManager->EntityDestroyed(entity);
}

Signature BaseCoordinator::GetSignature(Entity entity)
{
    return mEntityManager->GetSignature(entity);
}