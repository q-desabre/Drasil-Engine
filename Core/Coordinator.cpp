
#include "Coordinator.hpp"
#include "Components.hpp"
#include "Systems.hpp"

void Coordinator::Init(const std::string& windowName, const Vec2& windowSize)
{
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mEventManager = std::make_unique<EventManager>();
    mSystemManager = std::make_unique<SystemManager>();
    RegisterComponents();
    RegisterSystems();
    mRenderSystem = RegisterSystem<RenderSystem>();
    mRenderSystem->InitRender(windowName, windowSize);
}

void Coordinator::RegisterComponents()
{
    RegisterComponent<Gravity>();
    RegisterComponent<RigidBody>();
    RegisterComponent<Thrust>();
    RegisterComponent<Transform>();
    RegisterComponent<Player>();
}

void Coordinator::RegisterSystems()
{
    RegisterSystem<PhysicsSystem>();
    RegisterSystem<PlayerControlSystem>();
}

void Coordinator::UpdateSystems(float dt)
{
    mRenderSystem->ProcessEvents();
    mSystemManager->UpdateSystems(dt);
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