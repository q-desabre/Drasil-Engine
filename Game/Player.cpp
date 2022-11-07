
#include "Player.hpp"
#include "Manager.hpp"

Player::Player()
{
    gCoordinator.AddComponent(mID, InputComponent{});
    gCoordinator.AddComponent(mID, RenderComponent{.texture = "Img_Test"});
    
    gCoordinator.AddComponent(
        mID, ReplicatedComponent{
                 .types = {typeid(Transform), typeid(InputComponent)}});

    auto& render = gCoordinator.GetComponent<RenderComponent>(mID);
    render.sprite.setTexture(Textures.get(render.texture));
}

Player::~Player() {}