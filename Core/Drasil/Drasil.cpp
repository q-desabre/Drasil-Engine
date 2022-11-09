
#include "Drasil.hpp"

using namespace drasil;

Drasil::Drasil()
{
    gCoordinator.InitWithoutRender();
}

Drasil::Drasil(const std::string& name, const Vec2& winSize)
{
    gCoordinator.Init(name, winSize);
    gCoordinator.AddEventListener(
        METHOD_LISTENER(Events::Window::QUIT, Drasil::Stop));
}

Drasil::~Drasil() {}

void Drasil::Start()
{
    // loop to 60 fps

    auto start = std::chrono::high_resolution_clock::now();
    while (mIsRunning)
    {
        // cap to 60 fps
        if (mDelta > 1.0f / 60.0f)
        {
            start = std::chrono::high_resolution_clock::now();
            gCoordinator.UpdateSystems(mDelta);
        }
        auto end = std::chrono::high_resolution_clock::now();
        mDelta = std::chrono::duration<float, std::chrono::seconds::period>(
                     end - start)
                     .count();
    }
}

void Drasil::PushLevel(std::shared_ptr<Level> Level)
{
    gCoordinator.PushLevel(Level);
}

void Drasil::PopLevel()
{
    gCoordinator.PopLevel();
}

void Drasil::Stop(Event& event)
{
    mIsRunning = false;
}

void Drasil::StartServer(unsigned short port)
{
    gCoordinator.StartServer(port);
}

// TODO ADD IP
void Drasil::StartClient(unsigned short port)
{
    gCoordinator.StartClient(port);
    Start();
}