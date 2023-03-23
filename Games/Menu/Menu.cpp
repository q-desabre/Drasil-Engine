
#include "Menu.hpp"

Menu::Menu()
{
    s.SetTexture("Img_Test");
    s.SetPosition(200, 200);
    AddEntity(s.GetID());
    t.SetText("Hello World");
    t.SetPosition(100, 100);
    t.SetColor(255, 0, 0);
    AddEntity(t.GetID());
}