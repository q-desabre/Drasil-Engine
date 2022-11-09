
#pragma once

#include <SFML/Network.hpp>
#include <thread>
#include "Event.hpp"
#include "INetworkSystem.hpp"
#include "Packet.hpp"
#include "SafeQueue.hpp"
#include "SafeVector.hpp"

namespace drasil
{

    class NetworkSystem : public INetworkSystem
    {
    public:
        // System methods
        void InitSignature();
        void Update(float dt);

        // Start
        void StartServer(unsigned short port);
        void StartClient(unsigned short port);

        // Event Listener
        void RecvPacketListener(Event& event);
        void SendPacketListener(Event& event);

        // Thread udp
        void Listen();
        void ListenServer();

    private:
        bool mIsServer = false;
        SafeVector<unsigned short> mPorts;
        std::thread mListenThread;
        sf::UdpSocket mSocket;
        sf::IpAddress mSender;
        unsigned short mPort;
        unsigned short mClientPort = 0;
        Packet mPacket;
    };
}