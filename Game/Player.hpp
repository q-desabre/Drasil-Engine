
#pragma once

#include "Actor.hpp"
#include "IReplicated.hpp"

namespace drasil
{
    class Player : public Actor, public IReplicated
    {
    public:
        Player();
        ~Player();

        // add sf packet to make use of inheritance ?

        void CreateNetwork() override;

        void UpdateNetwork() override;

        void OnUpdateNetwork(drasil::Event& e) override;

        void DestroyNetwork() override;

        // void Create() override;  // call at the end of ctor on server
        // // catch by the factory client and create a new player

        // void Update() override;  // call by the network system
        // // catch by the class and call OnUpdate

        // void OnUpdate() override;  // update on client

        // void Destroy() override;  // call at the end of dtor on server
        // // catch by Coordinator and destroy the player
    };
}