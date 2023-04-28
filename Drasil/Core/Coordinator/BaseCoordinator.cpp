
#include "BaseCoordinator.hpp"
#include "../../Systems.hpp"
#include "../../Systems/Network/NetworkSystem.hpp"

using namespace drasil;

BaseCoordinator::BaseCoordinator()
{
    mLevelManager = std::make_unique<LevelManager>();
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mEventManager = std::make_unique<EventManager>();
    mSystemManager = std::make_unique<SystemManager>();
}

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

// Entity methods

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

// Event methods

void BaseCoordinator::AddEventListener(
    const std::string& eventId,
    std::function<void(Event&)> const& listener)
{
    mEventManager->AddListener(eventId, listener);
}

void BaseCoordinator::SendEvent(Event& event)
{
    mEventManager->SendEvent(event);
}

// Level

void BaseCoordinator::PushLevel(std::shared_ptr<Level> Level)
{
    mLevelManager->PushLevel(Level);
}

void BaseCoordinator::PopLevel()
{
    mLevelManager->PopLevel();
}
