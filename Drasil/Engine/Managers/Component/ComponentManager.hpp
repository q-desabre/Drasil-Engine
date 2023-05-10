#pragma once

#include <any>
#include <cstring>
#include <iostream>
#include <memory>
#include <unordered_map>
#include "../../../Common/Types/Types.hpp"
#include "ComponentArray.hpp"

namespace drasil
{

    class ComponentManager
    {
    public:
        ~ComponentManager() {}

        template <typename T>
        void RegisterComponent()
        {
            std::string typeName = typeid(T).name();

            assert(mComponentTypes.find(typeName) == mComponentTypes.end() &&
                   "Registering component type more than once.");

            mComponentTypes.insert({typeName, mNextComponentType});
            mComponentArrays.insert(
                {typeName, std::make_shared<ComponentArray<T>>()});

            ++mNextComponentType;
        }

        template <typename T>
        ComponentType GetComponentType()
        {
            std::string typeName = typeid(T).name();

            assert(mComponentTypes.find(typeName) != mComponentTypes.end() &&
                   "Component not registered before use.");

            return mComponentTypes[typeName];
        }

        template <typename T>
        void AddComponent(Entity entity, T component)
        {
            GetComponentArray<T>()->InsertData(entity, component);
        }

        template <typename T>
        void RemoveComponent(Entity entity)
        {
            GetComponentArray<T>()->RemoveData(entity);
        }

        template <typename T>
        T& GetComponent(Entity entity)
        {
            return GetComponentArray<T>()->GetData(entity);
        }

        void EntityDestroyed(Entity entity)
        {
            for (auto const& pair : mComponentArrays)
            {
                auto const& component = pair.second;

                component->EntityDestroyed(entity);
            }
        }

    private:
        std::unordered_map<std::string, ComponentType> mComponentTypes{};
        std::unordered_map<std::string, std::shared_ptr<IComponentArray>>
            mComponentArrays{};
        ComponentType mNextComponentType{};

        template <typename T>
        std::shared_ptr<ComponentArray<T>> GetComponentArray()
        {
            std::string typeName = typeid(T).name();

            assert(mComponentTypes.find(typeName) != mComponentTypes.end() &&
                   "Component not registered before use.");

            return std::static_pointer_cast<ComponentArray<T>>(
                mComponentArrays[typeName]);
        }
    };
}