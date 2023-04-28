
#pragma once

#include <map>
#include "Drasil/Drasil.hpp"
#include "Drasil/Systems/Render/ARenderSystem.hpp"
#include "Manager/Manager.hpp"
#include "SFML/Graphics.hpp"

namespace drasil
{
    class SfmlRenderSystem : public ARenderSystem
    {
    public:
        ~SfmlRenderSystem() {}
        void InitSignature();
        void InitRender(const std::string& windowName,
                        const Vec2& windowSize,
                        const std::string& assetsPath);
        void ProcessEvents();
        void Update(float dt);

        void SetWindowSize(const Vec2& windowSize);
        void SetWindowName(const std::string& windowName);
        void SetWindowFullScreen(bool isFullScreen);
        const Vec2& GetWindowSize() const;
        const std::string& GetWindowName() const;
        bool IsWindowFullScreen() const;

        void UpdateMouseEvent();
        void UpdateKeyboardEvent();

    private:
        void UpdateEntity(Event& event);
        void NotifyUpdate(Entity);
        void UpdateSprite(Entity, TransformComponent&, RenderComponent&);
        void UpdateText(Entity, TransformComponent&, RenderComponent&);
        void InitRessources(const std::string& path);

    private:
        std::string mWindowName;
        Vec2 mWindowSize;
        sf::Event mEvent;
        sf::RenderWindow mWindow;
        std::map<Entity, sf::Sprite> mSprites;
        std::map<Entity, sf::Text> mTexts;
        // Managers
        Manager<sf::Texture> mTextures;
        Manager<sf::Font> mFonts;
        Manager<sf::SoundBuffer> mSounds;
    };
}

extern "C" __declspec(
    dllexport) std::shared_ptr<drasil::ARenderSystem> CreateRenderSystem()
{
    return std::make_shared<drasil::SfmlRenderSystem>();
}

#define TEXTURE_COMP std::get<TextureComponent>(render.data)
#define TEXT_COMP std::get<TextComponent>(render.data)