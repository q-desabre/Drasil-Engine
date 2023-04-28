
#pragma once

#include "../Drasil.hpp"
#include "../Types.hpp"

#define METHOD_LISTENER(EventType, Listener) \
    EventType, std::bind(&Listener, this, std::placeholders::_1)

#define FUNCTION_LISTENER(EventType, Listener) \
    EventType, std::bind(&Listener, std::placeholders::_1)

#define BIND_EVENT(type, func) \
    gCoordinator.AddEventListener(METHOD_LISTENER(type, func))

#define BIND_PACKET_RECV(func) \
    gCoordinator.AddEventListener(METHOD_LISTENER("NetworkPacketRecieve", func))

#define BIND_MOUSE(func) \
    gCoordinator.AddEventListener(METHOD_LISTENER("mouse", func))

#define BIND_GAME_TICK(func) \
    gCoordinator.AddEventListener(METHOD_LISTENER("tick", func))

#define BIND_PACKET_SEND(func) \
    gCoordinator.AddEventListener(METHOD_LISTENER("NetworkPacketSend", func))
