
#pragma once

#include <chrono>
#include <memory>
#include <string>
#include "../Common/Types/Types.hpp"
#include "Level/Level.hpp"

namespace drasil
{
    class Core
    {
    public:
        Core();
        Core(const std::string& name,
             const Vec2& winSize,
             const std::string& assetsPath = "");

        ~Core();

        void LoadLevel(const std::string& levelName);
        void PushLevel(std::shared_ptr<Level> Level);
        void PopLevel();

        void StartServer(unsigned short port);
        void StartClient(unsigned short port);

        void Start();
        void Stop(Event& event);

    private:
        float mDelta = 0.0f;
        bool mIsRunning = true;
    };
}