
#include "Menu.hpp"
#include <filesystem>

Menu::Menu()
{
    FindGames();
    FindGraphicals();
    mInputEnabled = true;

    s.SetTexture("Background_Space");
    t.SetText("Drasil Engine Nexus");
    t.setFontSize(54);
    t.SetColor(255, 255, 255);
    t.SetOutlineThickness(2);
    t.SetOutlineColor(0, 0, 0);

    // b.se

    AddEntity(s.GetID());
    AddEntity(t.GetID());
    AddEntity(b.GetID());
    t.SetPosition(WINDOW_WIDTH / 2 - t.GetSize().x / 2, 100);
    b.SetPosition(WINDOW_WIDTH / 2 - b.GetSize().x / 2, 400);

    std::cout << "Button Width " << b.GetSize().x << std::endl;
    BIND_EVENT("keyboard", Menu::OnKeyboard);
    BIND_EVENT("tick", Menu::OnTick);

    b.SetOnClick(
        [this]()
        {
            auto it = mGames.begin();
            std::advance(it, mSelectedGame);
            std::cout << "Loading " << it->first << std::endl;
            //  drasil::Engine::LoadLevel(it->second);
        });
}

void Menu::OnTick(drasil::Event& e)
{
    drasil::EventManager::NotifyUpdateEntity(t.GetID());
    b.SetPosition(WINDOW_WIDTH / 2 - b.GetSize().x / 2, 400);
}

void Menu::OnKeyboard(drasil::Event& e)
{
    auto key = e.GetParam<drasil::KeyboardEvent>("data");
    if (key.action == drasil::KeyboardEvent::Action::RELEASE)
        mInputEnabled = true;

    if (key.key == drasil::KeyboardEvent::Key::LEFT &&
        key.action == drasil::KeyboardEvent::Action::PRESS)
    {
        mInputEnabled = false;
        if (mGames.size() > 0)
        {
            if (mSelectedGame == 0)
                mSelectedGame = mGames.size() - 1;
            // else decrement it
            else
                --mSelectedGame;
        }
    }
    else if (key.key == drasil::KeyboardEvent::Key::RIGHT &&
             key.action == drasil::KeyboardEvent::Action::PRESS)
    {
        mInputEnabled = false;
        // if there are games
        if (mGames.size() > 0)
        {
            // if selected game is the last game, set it to 0
            if (mSelectedGame == mGames.size() - 1)
                mSelectedGame = 0;
            // else increment it
            else
                ++mSelectedGame;
        }
    }
    auto it = mGames.begin();
    std::advance(it, mSelectedGame);
    t.SetText(it->first);
}

void Menu::FindGames()
{
    for (const auto& entry : std::filesystem::directory_iterator("Games"))
    {
        std::string name = entry.path().filename().string();
        name.erase(name.find_first_of('.'), name.size());
        auto pos = name.find("lib");
        if (pos != std::string::npos)
            name.erase(pos, 3);
        mGames[name] = entry.path().string();
    }
}

void Menu::FindGraphicals()
{
    for (const auto& entry : std::filesystem::directory_iterator("Graphicals"))
    {
        std::string name = entry.path().filename().string();
        name.erase(name.find_first_of('.'), name.size());
        auto pos = name.find("lib");
        if (pos != std::string::npos)
            name.erase(pos, 3);
        pos = name.find("render");
        if (pos != std::string::npos)
            name.erase(pos, 6);
        mGraphicals[name] = entry.path().string();
    }
}