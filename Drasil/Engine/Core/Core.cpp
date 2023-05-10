
#include "Core.hpp"
#include "../Coordinator/Coordinator.hpp"

using namespace drasil;

Core::Core() {}

Core::Core(const std::string& name,
           const Vec2& winSize,
           const std::string& assetsPath)
{
    gCoordinator.Init(name, winSize, assetsPath);
    gCoordinator.AddEventListener(METHOD_LISTENER("quit", Core::Stop));
}

Core::~Core() {}

void Core::Start()
{
    // loop to 60 fps

    auto start = std::chrono::high_resolution_clock::now();
    while (mIsRunning)
    {
        // cap to 60 fps
        if (mDelta > 1.0f / 60.0f)
        {
            Event event("tick");
            event.SetParam("delta", mDelta);
            gCoordinator.SendEvent(event);

            start = std::chrono::high_resolution_clock::now();
            gCoordinator.UpdateSystems(mDelta);
        }
        auto end = std::chrono::high_resolution_clock::now();
        mDelta = std::chrono::duration<float, std::chrono::seconds::period>(
                     end - start)
                     .count();
    }

    // Need to stop the engine instead of exiting the program
    std::exit(0);
    //   gCoordinator.PopLevel();
}

void Core::LoadLevel(const std::string& levelName) {}

void Core::PushLevel(std::shared_ptr<Level> Level)
{
    gCoordinator.PushLevel(Level);
}

void Core::PopLevel()
{
    gCoordinator.PopLevel();
}

void Core::Stop(Event& event)
{
    LogManager::Print(Events::Logs::Type::ENGINE, "Stopping Drasil...");
    mIsRunning = false;
}

void Core::StartServer(unsigned short port)
{
    gCoordinator.StartServer(port);
}

// TODO ADD IP
void Core::StartClient(unsigned short port)
{
    gCoordinator.StartClient(port);
    Start();
}