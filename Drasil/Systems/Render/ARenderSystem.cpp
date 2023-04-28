
#include "ARenderSystem.hpp"
#include "../../Drasil.hpp"

using namespace drasil;

void ARenderSystem::SendKeyboardEvent()
{
    Event event("keyboard");
    event.SetParam("data", mKeyboardEvent);
    gCoordinator.SendEvent(event);
}

void ARenderSystem::SendMouseEvent()
{
    Event event("mouse");
    event.SetParam("data", mMouseEvent);
    gCoordinator.SendEvent(event);
}