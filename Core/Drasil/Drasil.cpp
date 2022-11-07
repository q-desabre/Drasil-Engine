
#include "Drasil.hpp"

Drasil::Drasil()
{
    gCoordinator.InitWithoutRender();
}

Drasil::Drasil(const std::string& name, const Vec2& winSize)
{
    gCoordinator.Init(name, winSize);
    gCoordinator.AddEventListener(
        METHOD_LISTENER(Events::Window::QUIT, Drasil::Stop));
}

Drasil::~Drasil() {}

void Drasil::Start()
{
    // loop to 60 fps

    auto start = std::chrono::high_resolution_clock::now();
    while (mIsRunning)
    {
        // cap to 60 fps
        if (mDelta > 1.0f / 60.0f)
        {
            start = std::chrono::high_resolution_clock::now();
            gCoordinator.UpdateSystems(mDelta);
        }
        auto end = std::chrono::high_resolution_clock::now();
        mDelta = std::chrono::duration<float, std::chrono::seconds::period>(
                     end - start)
                     .count();
    }
}

void Drasil::PushLevel(std::shared_ptr<Level> Level)
{
    gCoordinator.PushLevel(Level);
}

void Drasil::PopLevel()
{
    gCoordinator.PopLevel();
}

void Drasil::Stop(Event& event)
{
    mIsRunning = false;
}

#include <SFML/Network.hpp>

void Drasil::StartServer()
{
    sf::IpAddress sender;
    sf::Packet packet;
    std::vector<int> ports;
    int type = 0;
    unsigned short port = -1;
    // upd broadcast
    sf::UdpSocket socket;
    socket.setBlocking(false);
    socket.bind(54000);
    while (1)
    {
        if (socket.receive(packet, sender, port) == sf::Socket::Done)
        {
            packet >> type;
            if (type == 1)
            {
                ports.push_back(port);
                std::cout << "Client connected on port: " << port << std::endl;
            }
        }
        std::cout << "Sending" << std::endl;
        sf::Packet packet;
        packet << "Hello";
        for (auto& port : ports)
        {
            socket.send(packet, sf::IpAddress::Broadcast, port);
        }
        // wait 1 second
        sf::sleep(sf::seconds(1));
    }
}

void Drasil::StartClient()
{
    // recieve sf::Packet on udp
    sf::UdpSocket socket;
    socket.setBlocking(false);
    socket.bind(54001);
    sf::Packet packet;
    packet << 1 << 54001;
    socket.send(packet, sf::IpAddress::Broadcast, 54000);
    while (1)
    {
        sf::Packet packet;
        sf::IpAddress sender;
        unsigned short port;
        std::cout << "Recieving.." << std::endl;
        if (socket.receive(packet, sender, port) == sf::Socket::Done)
        {
            std::string message;
            packet >> message;
            std::cout << "Message received from " << sender << ": " << message
                      << std::endl;
        }
        // wait 1 second
        sf::sleep(sf::seconds(1));
    }
}