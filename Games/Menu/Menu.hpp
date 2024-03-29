
#pragma once

#include <memory>
#include "Drasil/Drasil.hpp"

class Menu : public drasil::Level
{
public:
    Menu();

    void FindGames();
    void FindGraphicals();

    void OnTick(drasil::Event& e);
    void OnKeyboard(drasil::Event& e);

private:
    drasil::Sprite s;
    drasil::Text t;
    drasil::Button b;

    unsigned int mSelectedGame;
    unsigned int mSelectedGraphical;
    bool mInputEnabled;

    std::map<std::string, std::string> mGames;
    std::map<std::string, std::string> mGraphicals;
};

extern "C" __declspec(dllexport) std::shared_ptr<drasil::Level> CreateLevel()
{
    return std::make_shared<Menu>();
}