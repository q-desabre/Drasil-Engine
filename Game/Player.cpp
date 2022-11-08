
#include "Player.hpp"
#include "Macro.hpp"
#include "Manager.hpp"

Player::Player()
{
    gCoordinator.AddComponent(mID, InputComponent{});
    gCoordinator.AddComponent(mID, RenderComponent{.texture = "Img_Test"});
    // gCoordinator.AddComponent(
    //     mID,
    //     NetworkComponent{
    auto& render = gCoordinator.GetComponent<RenderComponent>(mID);
    render.sprite.setTexture(Textures.get(render.texture));

    // gCoordinator.AddEventListener(METHOD_LISTENER(
    //     Events::Network::PACKET_RECEIVED, Player::NetworkReceive));
}

Player::~Player() {}

void Player::Create()
{
    // Server
    // create sf packet and to packet to send
    // Client
    // BIND BY FACTORY
}

void Player::Update()
{
    // Server
    // create sf packet and to packet to send
    // Client
    // BIND BY CLASS -> OnUpdate ?
}

void Player::OnUpdate() {}

void Player::Destroy()
{
    // Server
    // create sf packet and to packet to send
    // Client
    // BIND BY GAME ?
}