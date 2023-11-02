#ifndef Time_Module
#define Time_Module
#include<iostream>
#include <limits>
#include<string>
using namespace std;
struct Time
{
    int hours;
    int minutes;
    int seconds;


    bool is_am()const;
    bool is_valid() const;
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>=(const Time& other) const;
    bool operator<=(const Time& other) const;

    Time operator+(int seconds) const;
    Time operator-(int seconds) const;

    //prefix
    Time& operator++();
    //postfix
    const Time operator++(int);
    Time& operator--();

    const Time operator--(int);


    string to_string(bool is_24 = true) const;


};
ostream& operator<<(ostream& os, const Time& time);

istream& operator>>(istream& is, Time& time);

#endif // !Time_Module


