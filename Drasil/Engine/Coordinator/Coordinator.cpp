
#include "Coordinator.hpp"

using namespace drasil;

typedef std::shared_ptr<ARenderSystem> (*CreateRenderSystemFunc)();

Coordinator& Coordinator::GetInstance()
{
    static Coordinator instance;
    return instance;
}

Coordinator::Coordinator() : BaseCoordinator()
{
    mLevelManager = std::make_unique<LevelManager>();
    mEventManager = std::make_unique<EventManager>();
}

void Coordinator::Init(const std::string& windowName,
                       const Vec2& windowSize,
                       const std::string& assetsPath)
{
    RegisterComponents();
    RegisterSystems();

    LoadRenderSystem("./Graphicals/libsfmlRender.dll");
    mRenderSystem->InitRender(windowName, windowSize, assetsPath);

    LogManager::Print(Events::Logs::Type::ENGINE, "Coordinator initialized");
}

void Coordinator::LoadRenderSystem(const std::string& path)
{
    mRenderLoader.Open(path);
    auto f =
        mRenderLoader.GetFunction<CreateRenderSystemFunc>("CreateRenderSystem");
    mRenderSystem = f();
    mSystemManager->RegisterRenderSystem(mRenderSystem);
    mRenderSystem->InitSignature();
    mRenderSystem->InitRender("Drasil", Vec2(800, 600), "./Assets/");
}

void Coordinator::PushLevel(std::shared_ptr<Level> Level)
{
    mLevelManager->PushLevel(Level);
}

void Coordinator::PopLevel()
{
    mLevelManager->PopLevel();
}

void Coordinator::AddEventListener(const std::string& eventId,
                                   Callback const& listener)
{
    mEventManager->AddListener(eventId, listener);
}

void Coordinator::SendEvent(Event& event)
{
    mEventManager->SendEvent(event);
}