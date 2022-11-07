
#pragma once

#include "System.hpp"

class NetworkSystem : public System
{
public:
    void InitSignature();

    void Update(float dt);
};
