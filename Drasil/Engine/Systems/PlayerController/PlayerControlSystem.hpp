#pragma once

#include <bitset>
#include "../ASystem.hpp"

namespace drasil
{
    class Event;

    class PlayerControlSystem : public ASystem
    {
    public:
        void InitSignature();

        void Update(float dt);

    private:
        std::bitset<8> mButtons;

        void InputListener(Event& event);
    };
}