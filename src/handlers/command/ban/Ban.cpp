#include "handlers/command/ban/Ban.h"

namespace ZiggyBot::Command
{
    //TODO: Delete all messages in database from banned user.
    void Ban::RunCommand(TgBot::Bot *bot, TgBot::Message::Ptr message)
    {
        std::vector args = ZiggyBot::Utils::MessageUtils::Split(message->text);

        TgBot::Message::Ptr reply = message->replyToMessage;
        if (reply != nullptr)
        {
            if (args.size() > 1)
            {
                int count = 0;
                std::string argsfromone;
                for (std::string s : args)
                {
                    if (!count)
                    {
                        count++;
                        continue;
                    }

                    argsfromone += s;
                    if (args.size() != count + 1)
                    {
                        argsfromone += " ";
                    }
                }
                std::pair units = Utils::TimeUtils::SplitTime(argsfromone);

                if (units.first.empty() || !units.second)
                {
                    bot->getApi().sendMessage(message->chat->id, "Bad args. Try again.", false,  message->messageId);
                    return;
                }

                unsigned long timestamp = Utils::TimeUtils::GetTimestamp(units.first, units.second);

                bot->getApi().kickChatMember(reply->chat->id, reply->from->id, timestamp);
            }
            
            // Third argument takes a unix timestamp for when the person is unbanned.
            // If the timestamp is greater than 366 days from current time, ban is permanent.
            // Timestamp used here is Dec. 31st 2099 @ 23:59:59 UTC
            bot->getApi().kickChatMember(reply->chat->id, reply->from->id, 4102444799);
        }
    }
}