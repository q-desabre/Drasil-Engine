
#include "Sprite.hpp"

using namespace drasil;
#include <iostream>

Sprite::Sprite()
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
    std::cout << "Sprite created " << mID << std::endl;
}

Sprite::Sprite(const std::string& texture)
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});

    SetTexture(texture);
    std::cout << "Sprite created " << mID << std::endl;
}

void Sprite::SetTexture(const std::string& texture)
{
    gCoordinator.AddComponent(mID, RenderComponent{.texture = texture});
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.sprite.setTexture(Textures.get(render.texture));
}

const Vec3& Sprite::GetPosition() const
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    return transform.position;
}

void Sprite::SetPosition(const Vec3& pos)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = pos;
}

void Sprite::SetPosition(float x, float y, float z)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = Vec3(x, y, z);
}

const Vec2 Sprite::GetSize() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return Vec2(render.sprite.getTextureRect().width,
                render.sprite.getTextureRect().height);
}