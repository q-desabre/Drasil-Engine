
#pragma once

#include "../Pawn/Pawn.hpp"

namespace drasil
{
    class Text : public Pawn
    {
    public:
        Text();
        Text(const std::string& text);

        void SetPosition(const Vec3& pos) override;
        void SetPosition(float x, float y, float z = 0) override;

        void SetText(const std::string& text);
        void SetFont(const std::string& path);
        void setFontSize(int size);
        void SetOutlineThickness(int thickness);
        void SetColor(unsigned char r,
                      unsigned char g,
                      unsigned char b,
                      unsigned char a = 255);
        void SetOutlineColor(unsigned char r,
                             unsigned char g,
                             unsigned char b,
                             unsigned char a = 255);

        int GetFontSize() const;
        int GetOutlineThickness() const;
        const Vec2& GetSize() const;
        const Vec4& GetColor() const;
        const Vec4& GetOutlineColor() const;
        const std::string& GetText() const;
    };
}  // namespace drasil
