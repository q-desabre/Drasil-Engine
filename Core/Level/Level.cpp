
#include "Level.hpp"
#include "Coordinator.hpp"

Level::Level()
{
    mSignature.set(gCoordinator.GetComponentType<Active>());
}

Level::~Level() {}

void Level::Deactivate()
{
    for (auto& entity : mEntities)
    {
        auto& active = gCoordinator.GetComponent<Active>(entity);
        active.status = false;
    }
}

void Level::Activate()
{
    for (auto& entity : mEntities)
    {
        auto& active = gCoordinator.GetComponent<Active>(entity);
        active.status = true;
    }
}

void Level::AddEntity(Entity entity)
{
    // check signature
    auto entitySignature = gCoordinator.GetSignature(entity);
    if ((entitySignature & mSignature) == mSignature)
    {
        mEntities.push_back(entity);
    }
}

void Level::Destroy()
{
    for (auto& entity : mEntities)
    {
        gCoordinator.DestroyEntity(entity);
    }
}