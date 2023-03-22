
#pragma once

#include "../Actor/Actor.hpp"

namespace drasil
{
    class Text : public Actor
    {
    public:
        Text();
        Text(const std::string& text);

        void SetText(const std::string& text);
        void SetFont(const std::string& path);
        void SetPosition(const Vec3& pos);
        void SetPosition(float x, float y, float z = 0);
        void SetColor(unsigned char r,
                      unsigned char g,
                      unsigned char b,
                      unsigned char a = 255);
    };
}  // namespace drasil
