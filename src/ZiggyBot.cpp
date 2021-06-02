#include "ZiggyBot.h"

namespace ZiggyBot
{
    int Bot::Run()
    {
        TgBot::Bot bot(Config::TOKEN);

        Commands *commands = new Commands();

        for (std::pair p : commands->CommandList)
        {
            Handlers::CommandHandler::AddCommand(&bot, p.second, p.first);
        }

        try
        {
            TgBot::TgWebhookTcpServer webhookServer(88, bot);
            bot.getApi().setWebhook(Config::WEBHOOKURL);
            webhookServer.start();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        return 0;
    }
}
