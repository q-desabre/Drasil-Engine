
#include "Pawn.hpp"
#include "../../Components/TransformComponent.hpp"
#include "../../Core/Coordinator/Coordinator.hpp"

using namespace drasil;

Pawn::Pawn()
{
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
}

Pawn::~Pawn() {}

const Vec3& Pawn::GetPosition() const
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    return transform.position;
}

const Vec3& Pawn::GetRotation() const
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    return transform.rotation;
}

const Vec3& Pawn::GetScale() const
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    return transform.scale;
}

void Pawn::SetPosition(const Vec3& pos)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = pos;
}

void Pawn::SetPosition(float x, float y, float z)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = Vec3(x, y, z);
}

void Pawn::SetRotation(const Vec3& rot)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.rotation = rot;
}

void Pawn::SetRotation(float x, float y, float z)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.rotation = Vec3(x, y, z);
}

void Pawn::SetScale(const Vec3& scale)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.scale = scale;
}

void Pawn::SetScale(float x, float y, float z)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.scale = Vec3(x, y, z);
}
