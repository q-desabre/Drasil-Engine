#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>

namespace drasil
{

    template <class T>
    class Manager
    {
    public:
        // Get the only instance of the class
        static Manager& getInstance()
        {
            static Manager<T> _instance;

            return _instance;
        }

        const T& get(const std::string& key)
        {
            try
            {
                return data.at(key);
            }
            catch (const std::out_of_range& e)
            {
                throw std::out_of_range("Key " + key + " not found");
            }
        }

        void add(const std::string& key, const std::string& path);

        // Disable the possibility to construct class by other means
        Manager(Manager& other) = delete;
        void operator=(const Manager& other) = delete;

    protected:
        Manager() {}

        std::map<std::string, T> data;
    };

    typedef Manager<sf::Texture> TextureManager;
    typedef Manager<sf::Font> FontManager;
    typedef Manager<sf::SoundBuffer> SoundManager;

#define Textures TextureManager::getInstance()
#define Fonts FontManager::getInstance()
#define Sounds SoundManager::getInstance()

}
