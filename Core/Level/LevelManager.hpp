
#pragma once

#include <memory>
#include <stack>
#include "Level.hpp"

class LevelManager
{
public:
    LevelManager();
    ~LevelManager();

    void PushLevel(std::shared_ptr<Level> Level);
    void PopLevel();

private:
    std::stack<std::shared_ptr<Level>> mLevels;
};
