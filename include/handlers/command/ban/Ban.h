#pragma once

#include <string>
#include <vector>

#include <tgbot/tgbot.h>

#include "utils/MessageUtils.h"
#include "utils/TimeUtils.h"

namespace ZiggyBot::Command
{
    class Ban
    {
    public:
        static void RunCommand(TgBot::Bot *bot, TgBot::Message::Ptr message);
    };
}