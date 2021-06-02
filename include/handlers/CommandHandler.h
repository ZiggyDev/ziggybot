#pragma once

#include <string>
#include <tgbot/tgbot.h>

namespace ZiggyBot::Handlers
{
    class CommandHandler
    {
    public:
        static void AddCommand(TgBot::Bot *bot, boost::function<void (TgBot::Bot*, TgBot::Message::Ptr)> commandFunc, std::string command)
        {
            bot->getEvents().onCommand(command, [&bot, &commandFunc](TgBot::Message::Ptr message) {
                commandFunc(bot, message);
            });
        }
    };
}