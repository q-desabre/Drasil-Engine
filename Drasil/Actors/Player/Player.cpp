
#include "Player.hpp"
#include "../../Engine/Components/InputComponent.hpp"
#include "../../Engine/Components/NetworkComponent.hpp"
#include "../../Engine/Coordinator/Coordinator.hpp"
#include "../../Engine/Systems/Network/Packet.hpp"

using namespace drasil;

Player::Player()
{
    std::cout << "Player created with id " << mID << std::endl;
    gCoordinator.AddComponent(mID, InputComponent{});

    SetTexture("Img_Test");

    gCoordinator.AddComponent(
        mID,
        NetworkComponent{.Create = std::bind(&Player::CreateNetwork, this),
                         .Update = std::bind(&Player::UpdateNetwork, this),
                         .OnUpdate = std::bind(&Player::OnUpdateNetwork, this,
                                               std::placeholders::_1),
                         .Destroy = std::bind(&Player::DestroyNetwork, this)});

    //  CreateNetwork();

    auto& network = gCoordinator.GetComponent<NetworkComponent>(mID);
    network.Create();

    BIND_PACKET_RECV(Player::OnUpdateNetwork);
}

Player::~Player()
{
    std::cout << "Player destroyed with id " << mID << std::endl;
}

void Player::CreateNetwork()
{
    std::cout << "CreateNetwork" << std::endl;
    Packet p;

    p << 1 << mID;
    // << mPosition.x << mPosition.y;
    Event e("NetworkPacketSend");
    e.SetParam("packet", p);
    gCoordinator.SendEvent(e);
}

void Player::UpdateNetwork()
{
    // std::cout << "here !" << std::endl;
    Packet p;

    p << 2 << mID;
    // << mPosition.x << mPosition.y;
    Event e("NetworkPacketSend");
    e.SetParam("packet", p);
    gCoordinator.SendEvent(e);
}

void Player::OnUpdateNetwork(Event& e)
{
    std::cout << "Recieve update packed player" << std::endl;

    Packet packet = e.GetParam<Packet>("packet");
    // int type << packet;
}

void Player::DestroyNetwork()
{
    Packet p;

    p << 3 << mID;
    Event e("NetworkPacketSend");
    e.SetParam("packet", p);
    gCoordinator.SendEvent(e);
}