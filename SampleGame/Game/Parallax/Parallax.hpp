
#pragma once

#include <vector>
#include "Drasil/Core.hpp"
#include "Drasil/Game.hpp"

class Parallax : public drasil::Actor
{
public:
    Parallax(drasil::Level& level);
    ~Parallax();

    void InitFrames(drasil::Level& l);
    void InitFrame(drasil::Level& l, const std::string& texture, float speed);
    void Update(drasil::Event& event);

private:
    std::vector<drasil::Sprite> mSprites;
};
