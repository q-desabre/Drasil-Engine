
#include "Text.hpp"

using namespace drasil;

Text::Text()
{
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    render.meta.type = RenderType::TEXT;
    render.data = TextComponent{.string = "Hello World",
                                .font = "Arcade",
                                .color = Vec4(255, 255, 255, 255)};
}

Text::Text(const std::string& text)
{
    gCoordinator.AddComponent(mID,
                              TransformComponent{.position = Vec3(500, 500, 0),
                                                 .rotation = Vec3(0, 0, 0),
                                                 .scale = Vec3(1, 1, 1)});
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    render.meta.type = RenderType::TEXT;
    render.data = TextComponent{
        .string = text, .font = "Arcade", .color = Vec4(255, 255, 255, 255)};
}

void Text::SetText(const std::string& text)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    std::get<TextComponent>(render.data).string = text;
}

void Text::SetFont(const std::string& fontName)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    std::get<TextComponent>(render.data).font = fontName;
}

void Text::SetPosition(const Vec3& pos)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = pos;
}

void Text::SetPosition(float x, float y, float z)
{
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = Vec3(x, y, z);
}

void Text::SetColor(unsigned char r,
                    unsigned char g,
                    unsigned char b,
                    unsigned char a)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.isModified = true;
    std::get<TextComponent>(render.data).color = Vec4(r, g, b, a);
}