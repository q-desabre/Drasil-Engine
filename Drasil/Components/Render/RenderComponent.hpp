
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
        bool isModified = false;
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
        Vec4 color;
    };

    struct RenderComponent
    {
        MetaComponent meta;
        std::variant<TextureComponent, TextComponent> data;
    };

}