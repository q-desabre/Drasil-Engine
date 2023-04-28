
#pragma once

// ENGINE
#include "Drasil/Actors.hpp"
#include "Drasil/Components.hpp"
#include "Drasil/Drasil.hpp"
#include "Drasil/Systems.hpp"
#include "Drasil/Types.hpp"

class MyLevel : public drasil::Level
{
public:
    MyLevel()
    {
        s.SetTexture("Img_Test");
        s.SetPosition(200, 200);
        AddEntity(s.GetID());
        t.SetText("Hello World");
        t.SetPosition(100, 100);
        t.SetColor(255, 0, 0);
        AddEntity(t.GetID());
    }

private:
    drasil::Sprite s;
    drasil::Text t;
};
