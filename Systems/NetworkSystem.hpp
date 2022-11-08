
#pragma once

#include <SFML/Network.hpp>
#include <thread>
#include "Event.hpp"
#include "SafeQueue.hpp"
#include "SafeVector.hpp"
#include "System.hpp"



class NetworkSystem : public System
{
public:
    // System methods
    void InitSignature();
    void Update(float dt);

    void StartServer(unsigned short port);
    void PacketListener(Event& event);
    void StartClient(unsigned short port);

    void Listen();
    void ListenServer();

private:
    // create struct to specify the destination of the packet and the
    // type
    SafeQueue<sf::Packet> mPacketQueue;
    SafeVector<unsigned short> mPorts;
    std::thread mListenThread;
    sf::UdpSocket mSocket;
    sf::IpAddress mSender;
    unsigned short mPort;
    unsigned short mClientPort = 0;
    sf::Packet mPacket;
};
