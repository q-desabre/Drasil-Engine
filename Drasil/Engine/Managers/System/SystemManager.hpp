#pragma once

#include <cassert>
#include <memory>
#include <unordered_map>
#include "../../Common/Types/Types.hpp"
#include "System.hpp"

namespace drasil
{

    class SystemManager
    {
    public:
        template <typename T>
        std::shared_ptr<T> RegisterSystem()
        {
            const char* typeName = typeid(T).name();

            assert(mSystems.find(typeName) == mSystems.end() &&
                   "Registering system more than once.");

            auto system = std::make_shared<T>();
            mSystems.insert({typeName, system});
            return system;
        }

        void RegisterRenderSystem(std::shared_ptr<System> system)
        {
            const char* typeName = typeid(ARenderSystem).name();

            assert(mSystems.find(typeName) == mSystems.end() &&
                   "Registering system more than once.");

            mSystems.insert({typeName, system});
        }

        template <typename T>
        void SetSignature(Signature signature)
        {
            const char* typeName = typeid(T).name();

            assert(mSystems.find(typeName) != mSystems.end() &&
                   "System used before registered.");

            mSignatures.insert({typeName, signature});
        }

        void EntityDestroyed(Entity entity)
        {
            for (auto const& pair : mSystems)
            {
                auto const& system = pair.second;

                system->mEntities.erase(entity);
            }
        }

        void EntitySignatureChanged(Entity entity, Signature entitySignature)
        {
            for (auto const& pair : mSystems)
            {
                auto const& type = pair.first;
                auto const& system = pair.second;
                auto const& systemSignature = mSignatures[type];

                if ((entitySignature & systemSignature) == systemSignature)
                {
                    system->mEntities.insert(entity);
                }
                else
                {
                    system->mEntities.erase(entity);
                }
            }
        }

        void UpdateSystems(float dt)
        {
            for (auto const& pair : mSystems)
            {
                auto const& system = pair.second;
                system->Update(dt);
            }
        }

    private:
        // had to replace const char * to handle mangling of .dll
        std::unordered_map<std::string, Signature> mSignatures{};
        std::unordered_map<std::string, std::shared_ptr<System>> mSystems{};
    };
}