#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include "../../Systems.hpp"
#include "../../Types.hpp"
#include "../Component/ComponentManager.hpp"
#include "../Entity/EntityManager.hpp"
#include "../Event/EventManager.hpp"
#include "../Level/LevelManager.hpp"
#include "../System/SystemManager.hpp"

namespace drasil
{
    class ARenderSystem;

    class Coordinator
    {
    protected:
        Coordinator();

    public:
        static Coordinator& GetInstance();

        void Init(const std::string& windowName,
                  const Vec2& windowSize,
                  const std::string& assetsPath);
        void InitWithoutRender();
        void UpdateSystems(float dt);

        // Entity methods
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        Signature GetSignature(Entity entity);

        // Event methods
        void AddEventListener(EventId eventId,
                              std::function<void(Event&)> const& listener);
        void SendEvent(Event& event);
        void SendEvent(EventId eventId);

        // Level

        void PushLevel(std::shared_ptr<Level> Level);
        void PopLevel();

        // Network methods
        void StartServer(unsigned short port);
        void StartClient(unsigned short port);

    private:
        void RegisterComponents();
        void RegisterSystems();
        void RegisterPhysicsSystem();

    private:
        // Core Managers
        std::unique_ptr<LevelManager> mLevelManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<EntityManager> mEntityManager;
        std::unique_ptr<EventManager> mEventManager;
        std::unique_ptr<SystemManager> mSystemManager;
        // Core Systems
        std::shared_ptr<ARenderSystem> mRenderSystem;
        std::shared_ptr<INetworkSystem> mNetworkSystem;

        // Template Methods

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
}

#define gCoordinator drasil::Coordinator::GetInstance()
#define GET_COMPONENT(entity, component) \
    gCoordinator.GetComponent<component>(entity)
