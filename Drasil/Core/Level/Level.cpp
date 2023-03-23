
#include "../../Drasil.hpp"

using namespace drasil;

Level::Level()
{
    mSignature.set(gCoordinator.GetComponentType<StatusComponent>());
}

Level::~Level() {}

void Level::Deactivate()
{
    for (auto& entity : mEntities)
    {
        auto& status = gCoordinator.GetComponent<StatusComponent>(entity);
        status.active = false;
    }
}

void Level::Activate()
{
    for (auto& entity : mEntities)
    {
        auto& status = gCoordinator.GetComponent<StatusComponent>(entity);
        status.active = true;
    }
}

void Level::AddEntity(Entity entity)
{
    GET_COMPONENT(entity, StatusComponent).active = true;
    auto entitySignature = gCoordinator.GetSignature(entity);
    if ((entitySignature & mSignature) == mSignature)
    {
        mEntities.push_back(entity);
    }
}

#include <iostream>

void Level::Destroy()
{
    for (auto& entity : mEntities)
    {
        gCoordinator.DestroyEntity(entity);
    }
}