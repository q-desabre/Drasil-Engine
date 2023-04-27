
#pragma once

#include "../Pawn/Pawn.hpp"

namespace drasil
{
    class Sprite : public Pawn
    {
    public:
        Sprite();
        Sprite(const std::string& path);

        void SetTexture(const std::string& path);
        const Vec2& GetSize() const;
    };

}  // namespace drasil
