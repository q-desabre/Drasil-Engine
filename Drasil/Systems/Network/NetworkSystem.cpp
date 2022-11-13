
#include "NetworkSystem.hpp"
#include "../../Components.hpp"
#include "../../Core/Event/EventManager.hpp"
#include "../../Tools.hpp"

using namespace drasil;

void NetworkSystem::InitSignature()
{
    Signature signature;
    signature.set(gCoordinator.GetComponentType<StatusComponent>());
    signature.set(gCoordinator.GetComponentType<NetworkComponent>());
    gCoordinator.SetSystemSignature<NetworkSystem>(signature);

    BIND_PACKET_RECV(NetworkSystem::RecvPacketListener);
    BIND_PACKET_SEND(NetworkSystem::SendPacketListener);
}

void NetworkSystem::StartServer(unsigned short port)
{
    mIsServer = true;
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
    Packet packet;
    packet << 1 << mClientPort;
    mSocket.send(packet, sf::IpAddress::LocalHost, port);
    mListenThread = std::thread(&NetworkSystem::Listen, this);
}

void NetworkSystem::SendPacketListener(Event& event)
{
    Packet packet = event.GetParam<Packet>(Events::Network::PACKET);
    // for each port
    int size = mPorts.Size();
    for (int i = 0; i < size; i++)
    {
        mSocket.send(packet, sf::IpAddress::LocalHost, mPorts[i]);
    }
}

void NetworkSystem::RecvPacketListener(Event& event)
{
    Packet packet = event.GetParam<Packet>(Events::Network::PACKET);
    std::string message;
    packet >> message;
    // std::cout << "Recieve : " << message << std::endl;

    if (mClientPort == 0)
    {
        Packet packet2;
        packet2 << "Hello from server";
        Event event(Events::Network::SEND_PACKET);
        event.SetParam<Packet>(Events::Network::PACKET, packet2);
        gCoordinator.SendEvent(event);
    }
}

void NetworkSystem::ListenServer()
{
    unsigned short port;
    std::cout << "Server started on " << mPort << std::endl;
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

            Event event(Events::Network::PACKET_RECEIVED);
            event.SetParam(Events::Network::PACKET, mPacket);
            gCoordinator.SendEvent(event);
        }
    }
}

void NetworkSystem::Listen()
{
    std::cout << "Connected to Server on port " << mClientPort << std::endl;
    while (1)
    {
        if (mSocket.receive(mPacket, mSender, mClientPort) == sf::Socket::Done)
        {
            Event event(Events::Network::PACKET_RECEIVED);
            event.SetParam(Events::Network::PACKET, mPacket);
            gCoordinator.SendEvent(event);
        }
    }
}

void NetworkSystem::Update(float dt)
{
    if (mIsServer)
    {
        for (auto entity : mEntities)
        {
            auto& status = gCoordinator.GetComponent<StatusComponent>(entity);
            if (status.active)
            {
                auto& network =
                    gCoordinator.GetComponent<NetworkComponent>(entity);
                if (network.Update)
                {
                    network.Update();
                }
            }
        }
    }
}
