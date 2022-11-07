
#include "Actor.hpp"

Actor::Actor()
{
    mID = gCoordinator.CreateEntity();
    gCoordinator.AddComponent(mID, Active());
    gCoordinator.AddComponent(mID, Gravity{Vec3(0.0f, 0, 0.0f)});
    gCoordinator.AddComponent(
        mID, RigidBody{.velocity = Vec3(0.0f, 0.0f, 0.0f),
                       .acceleration = Vec3(0.0f, 0.0f, 0.0f)});
    gCoordinator.AddComponent(mID, Transform{.position = Vec3(0, 0, 0),
                                             .rotation = Vec3(0, 0, 0),
                                             .scale = Vec3(1, 1, 1)});
}

Actor::~Actor() {}

Entity Actor::GetID() const
{
    return mID;
}