
#pragma once

#include "IRenderSystem.hpp"
#include "Manager/Manager.hpp"
#include "SFML/Graphics.hpp"

namespace drasil
{

    class RenderSystem : public IRenderSystem
    {
    public:
        RenderSystem() {}
        ~RenderSystem() {}

        void InitSignature();
        void InitRender(const std::string& windowName,
                        const Vec2& windowSize,
                        const std::string& assetsPath);
        void ProcessEvents();
        void Update(float dt);

    private:
        void InitRessources(const std::string& path);

    private:
        sf::RenderWindow mWindow;
    };
}