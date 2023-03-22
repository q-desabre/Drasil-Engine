
#pragma once

#include "../Actor/Actor.hpp"

namespace drasil
{
    class Sprite : public Actor
    {
    public:
        Sprite();
        Sprite(const std::string& path);

        void SetTexture(const std::string& path);

        const Vec3& GetPosition() const;
        void SetPosition(const Vec3& pos);
        void SetPosition(float x, float y, float z = 0);

        const Vec2 GetSize() const;
    };

}  // namespace drasil
