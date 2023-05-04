#pragma once

#include <any>
#include <unordered_map>
#include "EventData.hpp"
#include "EventTypes.hpp"

namespace drasil
{

    class Event
    {
    public:
        Event() = delete;

        explicit Event(const std::string& type)
            : mType(hash(type.c_str(), type.length()))
        {
        }

        explicit Event(EventId type) : mType(type) {}

        template <typename T>
        void SetParam(const std::string& id, T value)
        {
            mData[hash(id.c_str(), id.length())] = value;
        }

        template <typename T>
        void SetParam(ParamId id, T value)
        {
            mData[id] = value;
        }

        template <typename T>
        T GetParam(const std::string& id)
        {
            return std::any_cast<T>(mData[hash(id.c_str(), id.length())]);
        }

        template <typename T>
        T GetParam(ParamId id)
        {
            return std::any_cast<T>(mData[id]);
        }

        EventId GetType() const { return mType; }

    private:
        EventId mType;
        std::unordered_map<ParamId, std::any> mData;
    };
}