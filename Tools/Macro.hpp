
#pragma once

#include "Coordinator.hpp"
#include "ECS.hpp"

#define BIND_PACKET_RECV(func)     \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(Events::Network::PACKET_RECEIVED, func))

#define BIND_PACKET_SEND(func)     \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(Events::Network::SEND_PACKET, func))
