
#pragma once

#include <vector>
#include "ECS.hpp"
#include "StatusComponent.hpp"

namespace drasil
{

    class Level
    {
    public:
        Level();
        ~Level();

        void AddEntity(Entity entity);
        void Deactivate();
        void Activate();

        void Destroy();

    private:
        std::vector<Entity> mEntities;
        Signature mSignature;
    };
}