#pragma once

#include <iostream>
#include <memory>
#include "ComponentManager.hpp"
#include "ECS.hpp"
#include "EntityManager.hpp"
#include "EventManager.hpp"
#include "LevelManager.hpp"
#include "SystemManager.hpp"
#include "Vec2.hpp"

class IRenderSystem;

class Coordinator
{
protected:
    Coordinator(){};

public:
    static Coordinator& GetInstance()
    {
        static Coordinator instance;
        return instance;
    }

    void Init(const std::string& windowName, const Vec2& windowSize);
    void InitWithoutRender();
    void UpdateSystems(float dt);

    // Entity methods
    Entity CreateEntity();
    void DestroyEntity(Entity entity);
    // get Entity signature
    Signature GetSignature(Entity entity);

    void PushLevel(std::shared_ptr<Level> Level);
    void PopLevel();

    // Event methods
    void AddEventListener(EventId eventId,
                          std::function<void(Event&)> const& listener);
    void SendEvent(Event& event);
    void SendEvent(EventId eventId);

private:
    void RegisterComponents();
    void RegisterSystems();
    void RegisterPhysicsSystem();

private:
    std::unique_ptr<LevelManager> mLevelManager;
    std::shared_ptr<IRenderSystem> mRenderSystem;
    std::unique_ptr<ComponentManager> mComponentManager;
    std::unique_ptr<EntityManager> mEntityManager;
    std::unique_ptr<EventManager> mEventManager;
    std::unique_ptr<SystemManager> mSystemManager;

public:
    // Component methods
    template <typename T>
    void RegisterComponent()
    {
        mComponentManager->RegisterComponent<T>();
    }

    template <typename T>
    void AddComponent(Entity entity, T component)
    {
        mComponentManager->AddComponent<T>(entity, component);

        auto signature = mEntityManager->GetSignature(entity);
        signature.set(mComponentManager->GetComponentType<T>(), true);
        mEntityManager->SetSignature(entity, signature);

        mSystemManager->EntitySignatureChanged(entity, signature);
    }

    template <typename T>
    void RemoveComponent(Entity entity)
    {
        mComponentManager->RemoveComponent<T>(entity);

        auto signature = mEntityManager->GetSignature(entity);
        signature.set(mComponentManager->GetComponentType<T>(), false);
        mEntityManager->SetSignature(entity, signature);

        mSystemManager->EntitySignatureChanged(entity, signature);
    }

    template <typename T>
    T& GetComponent(Entity entity)
    {
        return mComponentManager->GetComponent<T>(entity);
    }

    template <typename T>
    ComponentType GetComponentType()
    {
        return mComponentManager->GetComponentType<T>();
    }

    // System methods
    template <typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        auto system = mSystemManager->RegisterSystem<T>();
        system->InitSignature();
        return system;
    }

    template <typename T>
    void SetSystemSignature(Signature signature)
    {
        mSystemManager->SetSignature<T>(signature);
    }
};

#define gCoordinator Coordinator::GetInstance()