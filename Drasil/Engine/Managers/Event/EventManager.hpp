#pragma once

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include "../../../Common/Types/Types.hpp"

namespace drasil
{
    using Callback = std::function<void(Event&)>;

    class EventManager
    {
    public:
        EventManager() {}

        void AddListener(EventId, Callback const&);
        void AddListener(const std::string&, Callback const&);

        void SendEvent(Event& event);

        static void NotifyUpdateEntity(Entity entity);

    private:
        std::map<EventId, std::list<Callback>> listeners;
    };
};
