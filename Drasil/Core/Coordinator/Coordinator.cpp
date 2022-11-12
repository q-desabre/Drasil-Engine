
#include "Coordinator.hpp"
#include "../../Components.hpp"
#include "../../Systems.hpp"

using namespace drasil;

Coordinator& Coordinator::GetInstance()
{
    static Coordinator instance;
    return instance;
}

Coordinator::Coordinator() {}

void Coordinator::Init(const std::string& windowName,
                       const Vec2& windowSize,
                       const std::string& assetsPath)
{
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mEventManager = std::make_unique<EventManager>();
    mSystemManager = std::make_unique<SystemManager>();
    mLevelManager = std::make_unique<LevelManager>();
    RegisterComponents();
    RegisterSystems();
    mRenderSystem = RegisterSystem<RenderSystem>();
    mRenderSystem->InitRender(windowName, windowSize, assetsPath);
}

void Coordinator::InitWithoutRender()
{
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mEventManager = std::make_unique<EventManager>();
    mSystemManager = std::make_unique<SystemManager>();
    mLevelManager = std::make_unique<LevelManager>();
    RegisterComponents();
    RegisterSystems();
}

// Network methods

void Coordinator::StartServer(unsigned short port)
{
    mNetworkSystem = RegisterSystem<NetworkSystem>();
    mNetworkSystem->StartServer(port);
}

void Coordinator::StartClient(unsigned short port)
{
    mNetworkSystem = RegisterSystem<NetworkSystem>();
    mNetworkSystem->StartClient(port);
}

void Coordinator::RegisterComponents()
{
    RegisterComponent<GravityComponent>();
    RegisterComponent<StatusComponent>();
    RegisterComponent<RigidBodyComponent>();
    RegisterComponent<TransformComponent>();
    RegisterComponent<InputComponent>();
    RegisterComponent<RenderComponent>();
    RegisterComponent<NetworkComponent>();
}

void Coordinator::RegisterSystems()
{
    RegisterSystem<PhysicsSystem>();
    RegisterSystem<PlayerControlSystem>();
}

void Coordinator::UpdateSystems(float dt)
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

Entity Coordinator::CreateEntity()
{
    return mEntityManager->CreateEntity();
}

void Coordinator::DestroyEntity(Entity entity)
{
    mEntityManager->DestroyEntity(entity);

    mComponentManager->EntityDestroyed(entity);

    mSystemManager->EntityDestroyed(entity);
}

Signature Coordinator::GetSignature(Entity entity)
{
    return mEntityManager->GetSignature(entity);
}

// Event methods

void Coordinator::AddEventListener(EventId eventId,
                                   std::function<void(Event&)> const& listener)
{
    mEventManager->AddListener(eventId, listener);
}

void Coordinator::SendEvent(Event& event)
{
    mEventManager->SendEvent(event);
}

void Coordinator::SendEvent(EventId eventId)
{
    mEventManager->SendEvent(eventId);
}

// Level

void Coordinator::PushLevel(std::shared_ptr<Level> Level)
{
    mLevelManager->PushLevel(Level);
}

void Coordinator::PopLevel()
{
    mLevelManager->PopLevel();
}
