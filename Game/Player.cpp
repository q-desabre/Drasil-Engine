
#include "Player.hpp"
#include "Manager.hpp"

Player::Player()
{
    gCoordinator.AddComponent(mID, InputComponent{});
    gCoordinator.AddComponent(mID, RenderComponent{.texture = "Img_Test"});
    auto& render = gCoordinator.GetComponent<RenderComponent>(mID);
    render.sprite.setTexture(Textures.get(render.texture));
}

Player::~Player() {}