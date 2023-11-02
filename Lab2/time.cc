#include "time.hpp"

bool Time::is_am() const
{
        return (*this < Time{ 12,0,0 });
    
}

bool Time::is_valid() const
{
    return (this->hours >= 0 && this->hours < 24) &&
        (this->minutes >= 0 && this->minutes < 60) &&
        (this->seconds >= 0 && this->seconds < 60);
}

bool Time::operator==(const Time& other) const
{
    return this->hours == other.hours && this->minutes == other.minutes && this->seconds == other.seconds;
}

bool Time::operator!=(const Time& other) const
{
    return !(*this == other);
}

bool Time::operator>(const Time& other) const
{
        if (!(this->hours == other.hours))
        {
            return this->hours > other.hours;
        }
        if (!(this->minutes == other.minutes))
        {
            return this->minutes > other.minutes;
        }
        return this->seconds > other.seconds;
}

bool Time::operator<(const Time& other) const
{
    if (!(this->hours == other.hours))
    {
        return this->hours < other.hours;
    }
    if (!(this->minutes == other.minutes))
    {
        return this->minutes < other.minutes;
    }
    return this->seconds < other.seconds;
}

bool Time::operator>=(const Time& other) const
{
    return (*this > other) || (*this == other);
}

bool Time::operator<=(const Time& other) const
{
    return (*this < other) || (*this == other);
}

Time Time::operator+(int seconds) const
{
    Time result{ this->hours,this->minutes,this->seconds };
    result.seconds += seconds;
    result.minutes += result.seconds / 60;
    result.seconds %= 60;
    result.hours += result.minutes / 60;
    result.minutes %= 60;
    result.hours %= 24;

    return result;
}

Time Time::operator-(int seconds) const
{
    Time result{ this->hours,this->minutes,this->seconds };
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

    if (result.hours < 0)
    {
        result.hours += 24;
    }

    return result;
}

Time& Time::operator++() //pre
{
    this->seconds += 1;
    this->minutes += this->seconds / 60;
    this->seconds %= 60;
    this->hours += this->minutes / 60;
    this->minutes %= 60;
    this->hours %= 24;
    return *this;
}

const Time Time::operator++(int) //post
{
    Time result{ this->hours,this->minutes,this->seconds };
    this->seconds += 1;
    this->minutes += this->seconds / 60;
    this->seconds %= 60;
    this->hours += this->minutes / 60;
    this->minutes %= 60;
    this->hours %= 24;
    return result;
}

Time& Time::operator--()
{
    this->seconds -= 1;
    if (this->seconds < 0)
    {
        int borrowMinutes = (-this->seconds + 59) / 60;
        this->minutes -= borrowMinutes;
        this->seconds += borrowMinutes * 60;
    }

    if (this->minutes < 0)
    {
        int borrowHours = (-this->minutes + 59) / 60;
        this->hours -= borrowHours;
        this->minutes += borrowHours * 60;
    }

    if (this->hours < 0)
    {
        this->hours += 24;
    }

    return *this;

}

const Time Time::operator--(int)
{
    Time result{ this->hours,this->minutes,this->seconds };
    this->seconds -= 1;
    if (this->seconds < 0)
    {
        int borrowMinutes = (-this->seconds + 59) / 60;
        this->minutes -= borrowMinutes;
        this->seconds += borrowMinutes * 60;
    }

    if (this->minutes < 0)
    {
        int borrowHours = (-this->minutes + 59) / 60;
        this->hours -= borrowHours;
        this->minutes += borrowHours * 60;
    }

    if (this->hours < 0)
    {
        this->hours += 24;
    }

    return result;
}

string Time::to_string(bool is_24) const
{
    if (!is_valid()) {
        //cout << "Invalid time input!" << endl;
        cerr << "Invalid time input!";
        return "";
    }
    if (is_24 == true) {
        return std::to_string(this->hours) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds);
    }
    else if (is_24 == false) {
        if (is_am()) {
            return std::to_string(this->hours) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds) + "[am]";
        }
        else if (this->hours == 12) {
            return std::to_string(this->hours) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds) + "[pm]";
        }
        else {
            return std::to_string(this->hours - 12) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds) + "[pm]";
        }
    }
    else {
        cerr << "invalid format input";
        return "";
    }
}

ostream& operator<<(ostream& os, const Time& time)
{
    os << time.to_string();
    return os;
}

istream& operator>>(istream& is, Time& time)
{
    char colon1, colon2;
    Time inputTime;
    is.clear();
    // Attempt to read hours, minutes, and seconds from input stream
    is >> inputTime.hours >> colon1 >> inputTime.minutes >> colon2 >> inputTime.seconds;

    // Check if the read values are within valid range
    if (is && colon1 == ':' && colon2 == ':' &&
        inputTime.is_valid()) {
        // Values are valid, update the Time object
        time.hours = inputTime.hours;
        time.minutes = inputTime.minutes;
        time.seconds = inputTime.seconds;
    }
    else {
        // Set the fail flag if input is incorrect
        is.setstate(ios::failbit);
    }
    if (is.fail()) {
        cout << "input is incorrect!" << endl;
    }
    return is;
}
