#pragma once

#include "../../Drasil.hpp"

namespace drasil
{

    class Event;

    class PlayerControlSystem : public System
    {
    public:
        void InitSignature();

        void Update(float dt);

    private:
        std::bitset<8> mButtons;

        void InputListener(Event& event);
    };
}