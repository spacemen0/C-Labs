#include "time.hpp"

bool is_am(const Time &time)
{
    return (time < Time{12, 0, 0});
}

bool is_valid(const Time &time)
{
    return (time.hours >= 0 && time.hours < 24) &&
           (time.minutes >= 0 && time.minutes < 60) &&
           (time.seconds >= 0 && time.seconds < 60);
}
bool operator<(const Time &lhs, const Time &rhs)
{
    return lhs.hours < rhs.hours || (lhs.hours == rhs.hours && lhs.minutes < rhs.minutes) || (lhs.hours == rhs.hours && lhs.minutes == rhs.minutes && lhs.seconds < rhs.seconds);
}
bool operator>(const Time &lhs, const Time &rhs)
{
    return !(lhs < rhs) && !(lhs == rhs);
}
bool operator==(const Time &lhs, const Time &rhs)
{
    return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes && lhs.seconds == rhs.seconds;
}

bool operator!=(const Time &lhs, const Time &rhs)
{
    return !(lhs == rhs);
}

bool operator>=(const Time &lhs, const Time &rhs)
{
    return lhs > rhs || lhs == rhs;
}
bool operator<=(const Time &lhs, const Time &rhs)
{
    return lhs < rhs || lhs == rhs;
}
Time operator+(const Time &time, int seconds)
{
    Time result{time.hours, time.minutes, time.seconds};
    result.seconds += seconds;
    result.minutes += result.seconds / 60;
    result.seconds %= 60;
    result.hours += result.minutes / 60;
    result.minutes %= 60;
    result.hours %= 24;

    return result;
}
Time operator-(const Time &time, int seconds)
{
    Time result{time.hours, time.minutes, time.seconds};
    result.seconds -= seconds;
    if (result.seconds < 0)
    {
        int borrowMinutes = (-result.seconds + 59) / 60;
        result.minutes -= borrowMinutes;
        result.seconds += borrowMinutes * 60;
    }

    if (result.minutes < 0)
    {
        int borrowHours = (-result.minutes + 59) / 60;
        result.hours -= borrowHours;
        result.minutes += borrowHours * 60;
    }

    while (result.hours < 0)
    {
        result.hours += 24;
    }

    return result;
}
Time &operator++(Time &time)
{
    time = time + 1;
    return time;
}
Time operator++(Time &time, int)
{
    Time result{time.hours, time.minutes, time.seconds};
    time = time + 1;
    return result;
}
Time &operator--(Time &time)
{
    time = time - 1;
    return time;
}
Time operator--(Time &time, int)
{
    Time result{time.hours, time.minutes, time.seconds};
    time = time - 1;
    return result;
}
std::string to_string(const Time &time, bool is_24)
{
    std::ostringstream oss;
    if (is_24)
    {
        oss << std::setfill('0') << std::setw(2) << time.hours << ":" << std::setw(2) << time.minutes << ":" << std::setw(2) << time.seconds;
    }
    else
    {
        int hours12 = time.hours % 12;
        if (hours12 == 0)
        {
            hours12 = 12;
        }

        oss << std::setfill('0') << std::setw(2) << hours12 << ":" << std::setw(2) << time.minutes << ":" << std::setw(2) << time.seconds;

        if (is_am(time))
        {
            oss << "[am]";
        }
        else
        {
            oss << "[pm]";
        }
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Time &time)
{
    os << to_string(time);
    return os;
}
std::istream &operator>>(std::istream &is, Time &time)
{
    char colon1, colon2;
    is >> std::setw(2) >> time.hours >> colon1 >> std::setw(2) >> time.minutes >> colon2 >> std::setw(2) >> time.seconds;

    if (colon1 != ':' || colon2 != ':' || !is_valid(time))
    {
        is.setstate(std::ios::failbit);
    }

    return is;
}
