
#pragma once

#include "Coordinator.hpp"
#include "ECS.hpp"

#define BIND_PACKET(func)          \
    gCoordinator.AddEventListener( \
        METHOD_LISTENER(Events::Network::PACKET_RECEIVED, func))
