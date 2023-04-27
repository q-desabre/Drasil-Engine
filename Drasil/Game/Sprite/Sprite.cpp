
#include "Sprite.hpp"
#include <iostream>

using namespace drasil;

Sprite::Sprite()
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    render.meta.type = RenderType::TEXTURE;
}

Sprite::Sprite(const std::string& texture)
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
    gCoordinator.AddComponent(mID, RenderComponent());
    SetTexture(texture);
}

void Sprite::SetTexture(const std::string& texture)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    render.meta.type = RenderType::TEXTURE;
    render.data = TextureComponent{.path = texture};
}

const Vec2& Sprite::GetSize() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    Vec2& size = std::get<TextureComponent>(render.data).size;
    return std::get<TextureComponent>(render.data).size;
}