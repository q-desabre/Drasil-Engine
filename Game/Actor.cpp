
#include "Actor.hpp"

using namespace drasil;

Actor::Actor()
{
    mID = gCoordinator.CreateEntity();
    gCoordinator.AddComponent(mID, StatusComponent());
    gCoordinator.AddComponent(mID, GravityComponent{Vec3(0.0f, 0, 0.0f)});
    gCoordinator.AddComponent(
        mID, RigidBodyComponent{.velocity = Vec3(0.0f, 0.0f, 0.0f),
                                .acceleration = Vec3(0.0f, 0.0f, 0.0f)});
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
}

Actor::~Actor() {}

Entity Actor::GetID() const
{
    return mID;
}