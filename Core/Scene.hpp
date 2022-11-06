
#pragma once

#include <vector>
#include "ECS.hpp"

class Scene
{
public:
    Scene();
    ~Scene();

    void AddEntity(Entity entity);
    void RemoveEntity(Entity entity);

    void Clear();

private:
    std::vector<Entity> mEntities;
};