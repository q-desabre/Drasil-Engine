
#pragma once

#include <map>
#include "ARenderSystem.hpp"
#include "Manager/Manager.hpp"
#include "SFML/Graphics.hpp"

namespace drasil
{
    class RenderSystem : public ARenderSystem
    {
    public:
        void InitSignature();
        void InitRender(const std::string& windowName,
                        const Vec2& windowSize,
                        const std::string& assetsPath);
        void ProcessEvents();
        void Update(float dt);

        void UpdateMouseEvent();
        void UpdateKeyboardEvent();

    private:
        void InitRessources(const std::string& path);

    private:
        sf::Event mEvent;
        sf::RenderWindow mWindow;
    };

    // No use since enum are in same order but usueful for other libs ?
    // static std::map<sf::Mouse::Button, MouseEvent::Button> MouseButtonTrsl =
    // {
    //     {sf::Mouse::Button::Left, MouseEvent::Button::LEFT},
    //     {sf::Mouse::Button::Right, MouseEvent::Button::RIGHT},
    //     {sf::Mouse::Button::Middle, MouseEvent::Button::MIDDLE},
    //     {sf::Mouse::Button::XButton1, MouseEvent::Button::X1},
    //     {sf::Mouse::Button::XButton2, MouseEvent::Button::X2}};
}