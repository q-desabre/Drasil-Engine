
#pragma once

#include "IRenderSystem.hpp"
#include "SFML/Graphics.hpp"

namespace drasil
{

    class RenderSystem : public IRenderSystem
    {
    public:
        void InitSignature();
        void InitRender(const std::string& windowName, const Vec2& windowSize);
        void ProcessEvents();
        void Update(float dt);

    private:
        void InitRessources(const std::string& path);

    private:
        sf::RenderWindow mWindow;
    };
}