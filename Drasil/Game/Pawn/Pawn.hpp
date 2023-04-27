
#pragma once

#include "../Actor/Actor.hpp"

namespace drasil
{
    class Pawn : public Actor
    {
    public:
        Pawn();
        ~Pawn();

        virtual void SetPosition(const Vec3& pos);
        virtual void SetPosition(float x, float y, float z = 0);

        void SetRotation(const Vec3& rot);
        void SetRotation(float x, float y, float z = 0);

        void SetScale(const Vec3& scale);
        void SetScale(float x, float y, float z = 0);

        virtual const Vec3& GetPosition() const;
        const Vec3& GetRotation() const;
        const Vec3& GetScale() const;
    };
}  // namespace drasil