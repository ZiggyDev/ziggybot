#pragma once

#include <any>
#include <map>
#include <string>

#include <boost/function.hpp>

#include "handlers/command/ban/Ban.h"

namespace ZiggyBot
{
    class Commands
    {
    public:
        const std::map<std::string, boost::function<void (TgBot::Bot*, TgBot::Message::Ptr)>> CommandList = {
            {"ban", &ZiggyBot::Command::Ban::RunCommand}
        };
    };
}