
#pragma once

#include <chrono>
#include "Coordinator.hpp"

class Drasil
{
public:
    Drasil();
    Drasil(const std::string& name, const Vec2& winSize);

    ~Drasil();

    void PushLevel(std::shared_ptr<Level> Level);
    void PopLevel();

    void StartServer();
    void StartClient();

    void Start();
    void Stop(Event& event);

private:
    float mDelta = 0.0f;
    bool mIsRunning = true;
};