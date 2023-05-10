
#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include "../../Components/Components.hpp"
#include "../../Systems/Systems.hpp"
#include "../../Managers/Component/ComponentManager.hpp"
#include "../../Managers/Entity/EntityManager.hpp"
#include "../../Managers/System/SystemManager.hpp"

namespace drasil
{
    class BaseCoordinator
    {
    protected:
        BaseCoordinator();
        std::unique_ptr<EntityManager> mEntityManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<SystemManager> mSystemManager;

        std::shared_ptr<ARenderSystem> mRenderSystem;
        std::shared_ptr<INetworkSystem> mNetworkSystem;

    public:
        void UpdateSystems(float dt);
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        Signature GetSignature(Entity entity);

        // Network methods
        void StartServer(unsigned short port);
        void StartClient(unsigned short port);

        // Getter
        std::shared_ptr<ARenderSystem> GetRenderSystem()
        {
            return mRenderSystem;
        }

    protected:
        void RegisterComponents();
        void RegisterSystems();
        void RegisterPhysicsSystem();

    public:
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

}  // namespace drasil
