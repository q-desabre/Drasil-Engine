
#pragma once

#include <vector>
#include "Active.hpp"
#include "ECS.hpp"

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