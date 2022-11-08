
#include "NetworkSystem.hpp"
#include "Components.hpp"
#include "Coordinator.hpp"
#include "Macro.hpp"

void NetworkSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<Active>());
    signature.set(gCoordinator.GetComponentType<NetworkComponent>());
    gCoordinator.SetSystemSignature<NetworkSystem>(signature);

    BIND_PACKET(NetworkSystem::PacketListener);
}

void NetworkSystem::StartServer(unsigned short port)
{
    mPort = port;
    mSocket.bind(mPort);
    mSocket.setBlocking(false);
    // start thread on listen
    mListenThread = std::thread(&NetworkSystem::ListenServer, this);
}

// TODO ADD IP
void NetworkSystem::StartClient(unsigned short port)
{
    mPort = port;
    mClientPort = port + 1;
    // try to bind to port until success
    while (mSocket.bind(mClientPort) != sf::Socket::Done)
    {
        mClientPort++;
    }
    mSocket.setBlocking(false);
    // say hello to server
    sf::Packet packet;
    packet << 1 << mClientPort;
    mSocket.send(packet, sf::IpAddress::LocalHost, port);
    mListenThread = std::thread(&NetworkSystem::Listen, this);
}

void NetworkSystem::PacketListener(Event& event)
{
    std::cout << "Event recieved" << std::endl;
    sf::Packet packet =
        event.GetParam<sf::Packet>(Events::Network::Packet::PACKET);
    std::string message;
    packet >> message;
    std::cout << message << std::endl;

    if (mClientPort == 0)
    {
        sf::Packet packet2;
        packet2 << "Hello from server";
        mPacketQueue.Push(packet2);
    }
}

void NetworkSystem::ListenServer()
{
    unsigned short port;
    std::cout << "Listening on port " << mPort << std::endl;
    while (1)
    {
        if (mSocket.receive(mPacket, mSender, port) == sf::Socket::Done)
        {
            if (mPorts.Find(port) == -1)
            {
                mPorts.Push(port);
                std::cout << "New client connected on port " << port
                          << std::endl;
            }

            // sleep
            //     std::this_thread::sleep_for(std::chrono::milliseconds(100000));
            std::cout << "Packet Recieved" << std::endl;
            Event event(Events::Network::PACKET_RECEIVED);
            event.SetParam(Events::Network::Packet::PACKET, mPacket);
            gCoordinator.SendEvent(event);
        }
    }
}

void NetworkSystem::Listen()
{
    std::cout << "Listening on port " << mClientPort << std::endl;
    while (1)
    {
        if (mSocket.receive(mPacket, mSender, mClientPort) == sf::Socket::Done)
        {
            std::cout << "Packet Recieved" << std::endl;
            Event event(Events::Network::PACKET_RECEIVED);
            event.SetParam(Events::Network::Packet::PACKET, mPacket);
            gCoordinator.SendEvent(event);
        }
    }
}

void NetworkSystem::Update(float dt)
{
    // send all packets to all ports
    while (!mPacketQueue.Empty())
    {
        sf::Packet packet = mPacketQueue.Pop();
        for (int i = 0; i < mPorts.Size(); i++)
        {
            std::cout << "Sending packet to port " << mPorts[i] << std::endl;
            mSocket.send(packet, sf::IpAddress::LocalHost, mPorts[i]);
        }
    }
}
