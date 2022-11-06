
#pragma once

#include "Components.hpp"
#include "Coordinator.hpp"

class Actor
{
public:
    Actor()
    {
        mID = gCoordinator.CreateEntity();
        gCoordinator.AddComponent<Actor>(mID, Gravity{Vec3(0.0f, 0, 0.0f)});
        gCoordinator.AddComponent(
            mID, RigidBody{.velocity = Vec3(0.0f, 0.0f, 0.0f),
                           .acceleration = Vec3(0.0f, 0.0f, 0.0f)});
        gCoordinator.AddComponent(
            mID, Transform{.position = Vec3(0, 0, 0),
                           .rotation = Vec3(0, 0, 0),
                           .scale = Vec3(scale, scale, scale)});
    }
    ~Actor() {}

protected:
    Entity mID;
};