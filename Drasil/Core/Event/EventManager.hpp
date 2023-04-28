#pragma once

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include "../../Types.hpp"
#include "Event.hpp"

namespace drasil
{

    class EventManager
    {
    public:
        EventManager() {}

        void AddListener(EventId, std::function<void(Event&)> const&);
        void AddListener(const std::string&,
                         std::function<void(Event&)> const&);

        void SendEvent(Event& event);

        static void NotifyUpdateEntity(Entity entity);

    private:
        std::map<EventId, std::list<std::function<void(Event&)>>> listeners;
    };
};
