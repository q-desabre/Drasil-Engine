#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

template <class T>
class Manager
{
public:
    Manager() {}
    ~Manager() {}

public:
    static Manager& getInstance(bool destroy = false)
    {
        static Manager* instance = nullptr;
        if (!instance)
            instance = new Manager();
        if (destroy)
        {
            delete instance;
            instance = nullptr;
        }
        return *instance;
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
    void clear()
    {
        // remove all T in data
        data.clear();
    }

    // Disable the possibility to construct class by other means
    Manager(Manager& other) = delete;
    void operator=(const Manager& other) = delete;

    std::map<std::string, T> data;
};
