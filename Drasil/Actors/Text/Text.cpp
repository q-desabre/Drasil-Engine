
#include "Text.hpp"
#include "../../Engine/Components/RenderComponent.hpp"
#include "../../Engine/Components/TransformComponent.hpp"
#include "../../Engine/Coordinator/Coordinator.hpp"

using namespace drasil;

Text::Text()
{
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.type = RenderType::TEXT;
    render.data = TextComponent{.string = "Hello World",
                                .font = "Trispace-Regular",
                                .fontSize = 30,
                                .color = Vec4(255, 255, 255, 255)};
    EventManager::NotifyUpdateEntity(mID);
}

Text::Text(const std::string& text)
{
    gCoordinator.AddComponent(mID, RenderComponent());
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.meta.type = RenderType::TEXT;
    render.data = TextComponent{.string = text,
                                .font = "Trispace-Regular",
                                .fontSize = 30,
                                .color = Vec4(255, 255, 255, 255)};
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetText(const std::string& text)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).string = text;
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetFont(const std::string& fontName)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).font = fontName;
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetPosition(const Vec3& pos)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = pos;
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetPosition(float x, float y, float z)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    auto& transform = GET_COMPONENT(mID, TransformComponent);
    transform.position = Vec3(x, y, z);
    EventManager::NotifyUpdateEntity(mID);
}

void Text::setFontSize(int size)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).fontSize = size;
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetOutlineThickness(int thickness)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).outlineThickness = thickness;
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetOutlineColor(unsigned char r,
                           unsigned char g,
                           unsigned char b,
                           unsigned char a)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).outlineColor = Vec4(r, g, b, a);
    EventManager::NotifyUpdateEntity(mID);
}

void Text::SetColor(unsigned char r,
                    unsigned char g,
                    unsigned char b,
                    unsigned char a)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    std::get<TextComponent>(render.data).color = Vec4(r, g, b, a);
    EventManager::NotifyUpdateEntity(mID);
}

const Vec2& Text::GetSize() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return std::get<TextComponent>(render.data).size;
}

const Vec4& Text::GetColor() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return std::get<TextComponent>(render.data).color;
}

int Text::GetFontSize() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return std::get<TextComponent>(render.data).fontSize;
}

int Text::GetOutlineThickness() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return std::get<TextComponent>(render.data).outlineThickness;
}

const Vec4& Text::GetOutlineColor() const
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    return std::get<TextComponent>(render.data).outlineColor;
}