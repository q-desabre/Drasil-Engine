
#include "Actor.hpp"
#include "../../Engine/Components/StatusComponent.hpp"
#include "../../Engine/Coordinator/Coordinator.hpp"

using namespace drasil;

Actor::Actor()
{
    mID = gCoordinator.CreateEntity();
    gCoordinator.AddComponent(mID, StatusComponent());
}

Actor::~Actor() {}

Entity Actor::GetID() const
{
    return mID;
}

bool Actor::IsActive() const
{
    auto& status = GET_COMPONENT(mID, StatusComponent);
    return status.active;
}

void Actor::SetActive(bool active)
{
    auto& status = GET_COMPONENT(mID, StatusComponent);
    status.active = active;
}