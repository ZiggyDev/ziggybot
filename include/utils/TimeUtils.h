#pragma once

#include <algorithm>
#include <chrono>
#include <locale>
#include <map>
#include <string>
#include <vector>

namespace ZiggyBot::Utils
{
    class TimeUtils
    {
    public:
        const std::map<std::vector<std::string>, long> units = 
        {
            {
                {"s", "sec", "second", "seconds", "null"},
                1
            },
            {
                {"mn", "min", "minute", "minutes", "null"},
                60
            },
            {
                {"h", "hr", "hour", "hours", "tigers", "null"},
                3600
            },
            {
                {"d", "dy", "day", "days", "null"},
                86400
            },
            {
                {"w", "wk", "week", "weeks", "null"},
                604800
            },
            {
                {"m", "mon", "month", "months", "null"},
                18144000
            },
            {
                {"y", "yr", "year", "years", "null"},
                31449600
            }
        };

        static std::pair<std::string, long> SplitTime(std::string);

        static unsigned long GetTimestamp(std::string unit, unsigned long value);
    };
}