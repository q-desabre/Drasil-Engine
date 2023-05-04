
#include "EventManager.hpp"
#include "../Coordinator/Coordinator.hpp"

using namespace drasil;

void EventManager::AddListener(const std::string& type,
                               const Callback& callback)
{
    listeners[hash(type.c_str(), type.length())].push_back(callback);
}

void EventManager::AddListener(EventId type, const Callback& callback)
{
    listeners[type].push_back(callback);
}

void EventManager::SendEvent(Event& event)
{
    EventId type = event.GetType();

    try
    {
        for (auto const& listener : listeners[type])
        {
            listener(event);
        }
    }
    catch (std::out_of_range& e)
    {
        // std::cout << "No listeners for event: " << type << std::endl;
        return;
    }
}

void EventManager::NotifyUpdateEntity(Entity entity)
{
    Event event("UpdateEntity");
    event.SetParam("entity", entity);
    gCoordinator.SendEvent(event);
}