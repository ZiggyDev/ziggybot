#include "utils/MessageUtils.h"

namespace ZiggyBot::Utils
{
    std::vector<std::string> MessageUtils::Split(std::string text)
    {
        std::vector<std::string> args;
        boost::algorithm::split(args, text, boost::is_any_of(" "), boost::algorithm::token_compress_on);

        return args;
    }
}