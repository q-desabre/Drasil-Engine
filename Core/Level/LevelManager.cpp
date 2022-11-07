
#include "LevelManager.hpp"

LevelManager::LevelManager() {}

LevelManager::~LevelManager() {}

void LevelManager::PushLevel(std::shared_ptr<Level> Level)
{
    if (!mLevels.empty())
        mLevels.top()->Deactivate();
    mLevels.push(Level);
    mLevels.top()->Activate();
}

void LevelManager::PopLevel()
{
    mLevels.top()->Destroy();
    mLevels.pop();
}