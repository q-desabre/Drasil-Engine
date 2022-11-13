
#pragma once

#include <bitset>
#include <cstdint>
#include <functional>

namespace drasil
{

    using Entity = std::uint32_t;
    const Entity MAX_ENTITIES = 5000;

    using ComponentType = std::uint8_t;
    const ComponentType MAX_COMPONENTS = 32;
    using Signature = std::bitset<MAX_COMPONENTS>;

    // used to create hash of string to id
    // Source: https://gist.github.com/Lee-R/3839813
    constexpr std::uint32_t fnv1a_32(char const* s, std::size_t count)
    {
        return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) *
               16777619u;  // NOLINT (hicpp-signed-bitwise)
    }

    constexpr std::uint32_t operator"" _hash(char const* s, std::size_t count)
    {
        return fnv1a_32(s, count);
    }

    // Events
    using EventId = std::uint32_t;
    using ParamId = std::uint32_t;

#define METHOD_LISTENER(EventType, Listener) \
    EventType, std::bind(&Listener, this, std::placeholders::_1)

#define FUNCTION_LISTENER(EventType, Listener) \
    EventType, std::bind(&Listener, std::placeholders::_1)

    namespace Events::Window
    {
        const EventId QUIT = "Events::Window::QUIT"_hash;
        const EventId RESIZED = "Events::Window::RESIZED"_hash;
        const EventId INPUT = "Events::Input"_hash;
    }

    namespace Events::Network
    {
        const EventId SEND_PACKET = "Events::Network::SEND_PACKET"_hash;
        const EventId PACKET_RECEIVED = "Events::Network::PACKET_RECEIVED"_hash;
        const ParamId PACKET = "Events::Network::PACKET"_hash;
    }

    namespace Events::Game
    {
        const ParamId DELTA = "Events::Game::DELTA"_hash;
        const EventId TICK = "Events::Game::GAME_LOOP"_hash;

        // IDEA FOR LATER
        const EventId LEVEL_CHANGED = "Events::Game::LEVEL_CHANGED"_hash;
        const EventId LEVEL_PUSHED = "Events::Game::LEVEL_PUSHED"_hash;
        const EventId LEVEL_POPPED = "Events::Game::LEVEL_POPPED"_hash;
        const EventId LEVEL_CLEARED = "Events::Game::LEVEL_CLEARED"_hash;
        const EventId LEVEL_LOADED = "Events::Game::LEVEL_LOADED"_hash;
        const EventId LEVEL_UNLOADED = "Events::Game::LEVEL_UNLOADED"_hash;
        const EventId LEVEL_RELOADED = "Events::Game::LEVEL_RELOADED"_hash;
        const EventId LEVEL_RESTARTED = "Events::Game::LEVEL_RESTARTED"_hash;
        const EventId LEVEL_PAUSED = "Events::Game::LEVEL_PAUSED"_hash;
        const EventId LEVEL_RESUMED = "Events::Game::LEVEL_RESUMED"_hash;
        const EventId LEVEL_STARTED = "Events::Game::LEVEL_STARTED"_hash;
        const EventId LEVEL_FINISHED = "Events::Game::LEVEL_FINISHED"_hash;
    }


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
            DELETE,
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

    namespace Events::Input
    {
        const EventId KEYBOARD = "Events::Input::KEYBOARD"_hash;
        const EventId MOUSE = "Events::Input::MOUSE"_hash;

        const ParamId MOUSE_DATA = "Events::Input::MOUSE_DATA"_hash;
        const ParamId KEYBOARD_DATA = "Events::Input::KEYBOARD_DATA"_hash;
    }

    namespace Events::Window::Resized
    {
        const ParamId WIDTH = "Events::Window::Resized::WIDTH"_hash;
        const ParamId HEIGHT = "Events::Window::Resized::HEIGHT"_hash;
    }
}