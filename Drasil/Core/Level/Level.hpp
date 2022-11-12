
#pragma once

#include <vector>
#include "../../Components.hpp"
#include "../../Types.hpp"

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