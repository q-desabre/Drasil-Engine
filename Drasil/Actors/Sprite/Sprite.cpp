
#include "Sprite.hpp"
#include <iostream>
#include "../../Engine/Components/MovementComponent.hpp"
#include "../../Engine/Components/RenderComponent.hpp"
#include "../../Engine/Components/TransformComponent.hpp"
#include "../../Engine/Coordinator/Coordinator.hpp"

using namespace drasil;

Sprite::Sprite()
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.type = RenderType::TEXTURE;
    EventManager::NotifyUpdateEntity(mID);
}

Sprite::Sprite(const std::string& texture)
{
    gCoordinator.AddComponent(mID, MovementComponent());
    gCoordinator.AddComponent(mID, RenderComponent());
    SetTexture(texture);
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetTexture(const std::string& texture)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.type = RenderType::TEXTURE;
    render.data = TextureComponent{.path = texture};
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetPosition(const Vec3& pos)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = pos;
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetPosition(float x, float y, float z)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = Vec3(x, y, z);
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetRotation(const Vec3& rot)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.rotation = rot;
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetRotation(float x, float y, float z)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.rotation = Vec3(x, y, z);
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetScale(const Vec3& scale)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.scale = scale;
    EventManager::NotifyUpdateEntity(mID);
}

void Sprite::SetScale(float x, float y, float z)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.scale = Vec3(x, y, z);
    EventManager::NotifyUpdateEntity(mID);
}

const Vec2& Sprite::GetSize() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    Vec2& size = std::get<TextureComponent>(render.data).size;
    return std::get<TextureComponent>(render.data).size;
}