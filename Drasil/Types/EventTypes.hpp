
#pragma once

#include "EventData.hpp"

namespace drasil
{
    // Events
    using EventId = std::uint32_t;
    using ParamId = std::uint32_t;

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

    namespace Events::Logs
    {
        enum class Type
        {
            // Can't USE ERROR because it's a win macro
            ENGINE,
            INFO,
            WARNING,
            FATAL
        };

        const EventId LOG = "Events::Log::INFO"_hash;
        const ParamId TYPE = "Events::Log::TYPE"_hash;
        const ParamId MESSAGE_TEXT = "Events::Log::MESSAGE_TEXT"_hash;
    }

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

    namespace Events::Input
    {
        const EventId KEYBOARD = "Events::Input::KEYBOARD"_hash;
        const EventId MOUSE = "Events::Input::MOUSE"_hash;

        const ParamId MOUSE_DATA = "Events::Input::MOUSE_DATA"_hash;
        const ParamId KEYBOARD_DATA = "Events::Input::KEYBOARD_DATA"_hash;
    }

    namespace Events::Window
    {
        const EventId RESIZE = "Events::Window::RESIZE"_hash;
        const ParamId WIDTH = "Events::Window::Resized::WIDTH"_hash;
        const ParamId HEIGHT = "Events::Window::Resized::HEIGHT"_hash;
    }
}  // namespace drasil
