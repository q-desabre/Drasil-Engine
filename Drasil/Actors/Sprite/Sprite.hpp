
#pragma once

#include "../Pawn/Pawn.hpp"

namespace drasil
{
    class Sprite : public Pawn
    {
    public:
        Sprite();
        Sprite(const std::string& path);

        void SetPosition(const Vec3& pos) override;
        void SetPosition(float x, float y, float z = 0) override;

        void SetRotation(const Vec3& rot) override;
        void SetRotation(float x, float y, float z = 0) override;

        void SetScale(const Vec3& scale) override;
        void SetScale(float x, float y, float z = 0) override;

        void SetTexture(const std::string& path);
        const Vec2& GetSize() const;
    };

}  // namespace drasil
