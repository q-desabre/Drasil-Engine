
#pragma once

#include "../../../Common/Types/Types.hpp"
#include "../ASystem.hpp"

namespace drasil
{
    class Event;

    class INetworkSystem : public ASystem
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