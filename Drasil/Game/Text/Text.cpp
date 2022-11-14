
#include "Text.hpp"

using namespace drasil;

Text::Text(Level& l)
{
    l.AddEntity(mID);
    std::cout << "Text created " << mID << std::endl;
    gCoordinator.AddComponent(mID, TransformComponent{.position = Vec3(0, 0, 0),
                                                      .rotation = Vec3(0, 0, 0),
                                                      .scale = Vec3(1, 1, 1)});
    gCoordinator.AddComponent(mID, RenderComponent{});
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.text.setFont(Fonts.get("Arcade"));
    render.text.setCharacterSize(24);
}

Text::Text(Level& l, const std::string& text)
{
    l.AddEntity(mID);
    std::cout << "Text created " << mID << std::endl;
    gCoordinator.AddComponent(mID,
                              TransformComponent{.position = Vec3(500, 500, 0),
                                                 .rotation = Vec3(0, 0, 0),
                                                 .scale = Vec3(1, 1, 1)});
    gCoordinator.AddComponent(mID, RenderComponent{.textString = text});
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.text.setFont(Fonts.get("Arcade"));
    render.text.setCharacterSize(24);
    // set color to yellow
    SetText(text);
}

void Text::SetText(const std::string& text)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.text.setString(text);
}

void Text::SetFont(const std::string& path)
{
    auto& render = GET_COMPONENT(mID, RenderComponent);
    render.text.setFont(Fonts.get("Arcade"));
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
    render.text.setFillColor(sf::Color(r, g, b, a));
}