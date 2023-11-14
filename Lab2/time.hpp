#ifndef Time_H
#define Time_H
#include <sstream>
#include <iomanip>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

bool is_am(const Time &time);
bool is_valid(const Time &time);
bool operator==(const Time &lhs, const Time &rhs);
bool operator!=(const Time &lhs, const Time &rhs);
bool operator>(const Time &lhs, const Time &rhs);
bool operator<(const Time &lhs, const Time &rhs);
bool operator>=(const Time &lhs, const Time &rhs);
bool operator<=(const Time &lhs, const Time &rhs);
Time operator+(const Time &time, int seconds);
Time operator-(const Time &time, int seconds);
Time &operator++(Time &time);
Time operator++(Time &time, int);
Time &operator--(Time &time);
Time operator--(Time &time, int);
std::string to_string(const Time &time, bool is_24 = true);
std::ostream &operator<<(std::ostream &os, const Time &time);
std::istream &operator>>(std::istream &is, Time &time);

#endif // !Time_H
