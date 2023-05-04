
#pragma once

#include "../../Common/Types/Types.hpp"

namespace drasil
{
    class Actor
    {
    public:
        Actor();
        ~Actor();

        Entity GetID() const;
        bool IsActive() const;
        void SetActive(bool active);

    protected:
        Entity mID;
    };
}