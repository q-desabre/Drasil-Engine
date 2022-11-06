
#pragma once

#include "Player.hpp"
#include "Scene.hpp"

class TestScene : public Scene
{
public:
    TestScene() { Player p; }

    ~TestScene() {}
};
