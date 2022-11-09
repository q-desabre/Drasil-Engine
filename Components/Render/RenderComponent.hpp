
#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace drasil
{
    struct RenderComponent
    {
        std::string texture;
        sf::Sprite sprite;
    };
}