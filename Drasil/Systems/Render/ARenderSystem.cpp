
#include "ARenderSystem.hpp"
#include "../../Core.hpp"

using namespace drasil;

void ARenderSystem::SendKeyboardEvent()
{
    Event event(Events::Input::KEYBOARD);
    event.SetParam(Events::Input::KEYBOARD_DATA, mKeyboardEvent);
    gCoordinator.SendEvent(event);
}

void ARenderSystem::SendMouseEvent()
{
    Event event(Events::Input::MOUSE);
    event.SetParam(Events::Input::MOUSE_DATA, mMouseEvent);
    gCoordinator.SendEvent(event);
}