
#pragma once

#include "../../Core/System/System.hpp"

namespace drasil
{
    class Event;

    class INetworkSystem : public System
    {
    public:
        virtual void StartServer(unsigned short port) = 0;
        virtual void StartClient(unsigned short port) = 0;
        virtual void RecvPacketListener(Event& event) = 0;
        virtual void SendPacketListener(Event& event) = 0;
        virtual void Listen() = 0;
        virtual void ListenServer() = 0;
    };
}