
#include "Parallax.hpp"
#include "Drasil/Components.hpp"
#include "Drasil/Core.hpp"
#include "Drasil/Types.hpp"
#include "Drasil/Utils.hpp"

using namespace drasil;

Parallax::Parallax(Level& l)
{
    InitFrames(l);
    BIND_GAME_TICK(Parallax::Update);
}

Parallax::~Parallax() {}

void Parallax::InitFrames(drasil::Level& l)
{
    InitFrame(l, "Parallax_Blue", -50);
    InitFrame(l, "Parallax_Star1", -60);
    InitFrame(l, "Parallax_Star2", -75);
    InitFrame(l, "Parallax_Star3", -100);
    InitFrame(l, "Parallax_Star4", -125);
}

void Parallax::InitFrame(drasil::Level& l,
                         const std::string& texture,
                         float speed)
{
    // first
    mSprites.emplace(mSprites.begin(), Sprite(texture));
    auto& mvt = GET_COMPONENT(mSprites[0].GetID(), MovementComponent);
    mvt.velocity = drasil::Vec3(speed, 0, 0);
    l.AddEntity(mSprites[0].GetID());

    // second
    float w = mSprites[0].GetSize().x;
    mSprites.emplace(mSprites.begin(), Sprite(texture));
    mSprites[0].SetPosition(w, 0, 0);
    l.AddEntity(mSprites[0].GetID());
    auto& mvt2 = GET_COMPONENT(mSprites[0].GetID(), MovementComponent);
    mvt2.velocity = drasil::Vec3(speed, 0, 0);
}

void Parallax::Update(drasil::Event& event)
{
    for (auto& sprite : mSprites)
    {
        auto& transform = GET_COMPONENT(sprite.GetID(), TransformComponent);
        if (transform.position.x < -(sprite.GetSize().x))
        {
            transform.position.x += sprite.GetSize().x * 2;
        }
    }
}