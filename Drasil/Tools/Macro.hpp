
#pragma once

#include "../Core.hpp"
#include "../Types.hpp"

#define BIND_PACKET_RECV(func)     \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(drasil::Events::Network::PACKET_RECEIVED, func))

#define BIND_MOUSE(func)           \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(drasil::Events::Input::MOUSE, func))

#define BIND_GAME_TICK(func)       \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(drasil::Events::Game::TICK, func))

#define BIND_PACKET_SEND(func)     \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(drasil::Events::Network::SEND_PACKET, func))
