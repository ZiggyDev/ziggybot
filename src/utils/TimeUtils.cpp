#include "utils/TimeUtils.h"

namespace ZiggyBot::Utils
{
    bool isNum(char c)
    {
        std::locale locale;
        return std::use_facet<std::ctype<char>>(locale).is(std::ctype<char>::digit, c);
    }

    std::pair<std::string, long> TimeUtils::SplitTime(std::string arg)
    {
        std::string unit = "";
        std::string numbers = "";
        int count = 0;

        for (char c : arg)
        {
            if (isNum(c))
            {
                numbers += c;
                count++;
                continue;
            }
            if (c != ' ')
            {
                unit += arg.substr(count);
            }
        }

        return std::pair<std::string, long>({unit, std::stoi(numbers)});
    }

    unsigned long TimeUtils::GetTimestamp(std::string unitString, unsigned long value)
    {
        long selectedRatio = 0;

        TimeUtils *timeutils = new TimeUtils();

        for (const auto& unit : timeutils->units)
        {
            std::string position = unit.first.at(unit.first.begin()->find(unitString));
            if (position != "null")
            {
                selectedRatio = unit.second;
                break;
            }
        }

        if (selectedRatio != 0)
        {
            return (std::chrono::system_clock::now().time_since_epoch().count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den) + (selectedRatio * value);
        }

        return 0;
    }
}