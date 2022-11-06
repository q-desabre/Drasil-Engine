
#include "Scene.hpp"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::AddEntity(Entity entity)
{
    mEntities.push_back(entity);
}

void Scene::RemoveEntity(Entity entity)
{
    auto it = std::find(mEntities.begin(), mEntities.end(), entity);
    if (it != mEntities.end())
    {
        mEntities.erase(it);
    }
}

void Scene::Clear()
{
    mEntities.clear();
}
