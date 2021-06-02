#pragma once

#include <boost/bind.hpp>

#include <tgbot/tgbot.h>

#include <any>
#include <exception>
#include <string>
#include <map>

#include "config/Config.h"
#include "handlers/command/Commands.h"
#include "handlers/CommandHandler.h"

namespace ZiggyBot
{
    class Bot
    {
    public:
        static int Run();
    };
}