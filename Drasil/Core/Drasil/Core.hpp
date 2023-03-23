
#pragma once

#include <chrono>
#include <memory>
#include <string>
#include "../../Types.hpp"
#include "../Event/Event.hpp"
#include "../Level/Level.hpp"

// class Level;
// class Event;

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