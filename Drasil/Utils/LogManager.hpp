
#pragma once

#include <iostream>
#include "../Types.hpp"

namespace drasil
{
    class LogManager
    {
    public:
        LogManager();

        static void Print(Events::Logs::Type type, const std::string& data)
        {
            switch (type)
            {
            case Events::Logs::Type::ENGINE:
                std::cout << "[ENGINE] -> " << data << std::endl;
                break;
                // case Events::Logs::Type::INFO:
                //     std::cout << "[INFO] -> " << data << std::endl;
                //     break;
                // case Events::Logs::Type::WARNING:
                //     std::cout << "/!\\ WARNING /!\\ ->" << data << std::endl;
                //     break;
                // case Events::Logs::Type::ERROR:
                //     std::cout << "/!\\ ERROR /!\\ ->" << data << std::endl;
                //     break;

            default:
                break;
            }
        }
    };
};
