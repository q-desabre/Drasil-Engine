
#pragma once

namespace drasil
{
    struct MouseEvent
    {
        enum class Button
        {
            LEFT,
            MIDDLE,
            RIGHT,
            X1,
            X2
        };

        enum class Action
        {
            PRESS,
            RELEASE,
            MOVE
        };

        Button button;
        Action action;
        int prevX;
        int prevY;
        int x;
        int y;
    };

    struct KeyboardEvent
    {
        enum class Key
        {
            UNKNOWN,
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            NUM0,
            NUM1,
            NUM2,
            NUM3,
            NUM4,
            NUM5,
            NUM6,
            NUM7,
            NUM8,
            NUM9,
            ESCAPE,
            LCONTROL,
            LSHIFT,
            LALT,
            LSYSTEM,
            RCONTROL,
            RSHIFT,
            RALT,
            RSYSTEM,
            MENU,
            LBRACKET,
            RBRACKET,
            SEMICOLON,
            COMMA,
            PERIOD,
            QUOTE,
            SLASH,
            BACKSLASH,
            TILDE,
            EQUAL,
            DASH,
            SPACE,
            RETURN,
            BACKSPACE,
            TAB,
            PAGEUP,
            PAGEDOWN,
            END,
            HOME,
            INSERT,
            DEL,
            ADD,
            SUBTRACT,
            MULTIPLY,
            DIVIDE,
            LEFT,
            RIGHT,
            UP,
            DOWN,
            NUMPAD0,
            NUMPAD1,
            NUMPAD2,
            NUMPAD3,
            NUMPAD4,
            NUMPAD5,
            NUMPAD6,
            NUMPAD7,
            NUMPAD8,
            NUMPAD9,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            PAUSE
        };

        enum class Action
        {
            PRESS,
            RELEASE
        };

        Key key;
        Action action;
    };

}  // namespace drasil
