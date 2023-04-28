
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

namespace drasil
{
    enum class RenderType
    {
        TEXTURE,
        TEXT
    };

    struct MetaComponent
    {
        RenderType type;
    };

    struct TextureComponent
    {
        MetaComponent meta;
        std::string path;
        Vec2 size;
    };

    struct TextComponent
    {
        MetaComponent meta;
        std::string string;
        std::string font;
        int fontSize;
        Vec2 size;  // Need to be set by the render system
        Vec4 color;
        int outlineThickness;
        Vec4 outlineColor;
    };

    struct RenderComponent
    {
        MetaComponent meta;
        std::variant<TextureComponent, TextComponent> data;
    };

}