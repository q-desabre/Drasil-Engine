#pragma once

#include "../../Common/Common.hpp"
#include "../Event/EventManager.hpp"
#include "../Level/LevelManager.hpp"
#include "BaseCoordinator.hpp"

namespace drasil
{
    class Coordinator : public BaseCoordinator
    {
    protected:
        Coordinator();

    public:
        static Coordinator& GetInstance();

        void Init(const std::string& windowName,
                  const Vec2& windowSize,
                  const std::string& assetsPath);

        void LoadRenderSystem(const std::string& path);

        // Level
        void PushLevel(std::shared_ptr<Level> Level);
        void PopLevel();

        // Event methods
        void AddEventListener(const std::string&, Callback const& listener);
        void SendEvent(Event& event);

    private:
        std::unique_ptr<LevelManager> mLevelManager;
        std::unique_ptr<EventManager> mEventManager;

        DynamicLoader mRenderLoader;
    };
}

#include "Macro.hpp"