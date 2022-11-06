
#pragma once

#include <memory>
#include <stack>
#include "Scene.hpp"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

private:
    std::stack<std::shared_ptr<Scene>> mScenes;
};
