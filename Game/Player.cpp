
#include "Player.hpp"
#include "Macro.hpp"
#include "Manager.hpp"

using namespace drasil;

Player::Player()
{
    std::cout << "Player created with id " << mID << std::endl;
    gCoordinator.AddComponent(mID, InputComponent{});

    // gCoordinator.AddComponent(mID, RenderComponent{.texture = "Img_Test"});

    gCoordinator.AddComponent(
        mID,
        NetworkComponent{.Create = std::bind(&Player::CreateNetwork, this),
                         .Update = std::bind(&Player::UpdateNetwork, this),
                         .OnUpdate = std::bind(&Player::OnUpdateNetwork, this,
                                               std::placeholders::_1),
                         .Destroy = std::bind(&Player::DestroyNetwork, this)});

    // auto& render = gCoordinator.GetComponent<RenderComponent>(mID);
    // render.sprite.setTexture(Textures.get(render.texture));
    //    CreateNetwork();

    auto& network = gCoordinator.GetComponent<NetworkComponent>(mID);
    network.Create();

    BIND_PACKET_RECV(Player::OnUpdateNetwork);
}

Player::~Player() {}

void Player::CreateNetwork()
{
    std::cout << "CreateNetwork" << std::endl;
    Packet p;

    p << 1 << mID;
    // << mPosition.x << mPosition.y;
    Event e(Events::Network::SEND_PACKET);
    e.SetParam(Events::Network::PACKET, p);
    gCoordinator.SendEvent(e);
}

void Player::UpdateNetwork()
{
    // std::cout << "here !" << std::endl;
    Packet p;

    p << 2 << mID;
    // << mPosition.x << mPosition.y;
    Event e(Events::Network::SEND_PACKET);
    e.SetParam(Events::Network::PACKET, p);
    gCoordinator.SendEvent(e);
}

void Player::OnUpdateNetwork(Event& e)
{
    Packet packet = e.GetParam<Packet>(Events::Network::PACKET);
    std::cout << "Recieve update packed player" << std::endl;
}

void Player::DestroyNetwork()
{
    Packet p;

    p << 3 << mID;
    Event e(Events::Network::SEND_PACKET);
    e.SetParam(Events::Network::PACKET, p);
    gCoordinator.SendEvent(e);
}