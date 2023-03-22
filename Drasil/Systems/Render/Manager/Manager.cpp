#include "Manager.hpp"

#include <iostream>
#include <memory>

template <>
void Manager<sf::Font>::add(const std::string& key, const std::string& path)
{
    sf::Font font;
    font.loadFromFile(path);  // TODO EXCEPTION
    data[key] = font;
}

template <>
void Manager<sf::Texture>::add(const std::string& key, const std::string& path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
        std::cerr << "Failed to load texture " << path
                  << std::endl;  // TODO EXCEPTION
    data[key] = texture;
}

// template <>
// void Manager<std::shared_ptr<sf::Shader>>::add(const std::string& key,
//                                                const std::string& path)
// {
//     std::shared_ptr<sf::Shader> shader = std::make_shared<sf::Shader>();
//     if (!shader->loadFromFile(path, sf::Shader::Fragment))
//         std::cerr << "Couldn't load fragment shader\n";
//     data[key] = shader;
// }

template <>
void Manager<sf::SoundBuffer>::add(const std::string& key,
                                   const std::string& path)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(path))
        std::cerr << "Failed to load sound " << path
                  << std::endl;  // TODO EXCEPTION
    data[key] = buffer;
}
