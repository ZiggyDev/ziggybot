#pragma once

#include <vector>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

namespace ZiggyBot::Utils
{
    class MessageUtils
    {
    public:
        static std::vector<std::string> Split(std::string text);
    };
}