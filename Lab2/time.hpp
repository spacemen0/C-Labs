#ifndef Time_Module
#define Time_Module
#include<iostream>
#include <limits>
#include<string>

// TODO: Complementary work needed: Do not open namespaces in header files  
// (using namespace). 
//
// TODO: Complementary work needed: All functions should not be a part of the
// Time struct, but free standing.
//
// TODO: Complementary work needed: Include headers that you use,
// do NOT include headers you do NOT use.
//
// TODO: Complementary work needed: postfix increment/decrement should not
// return a const Time.
//
// TODO: Complementary work needed: Your tests are insufficent, adding/subtracting
// should be tested when input is a large number (such as three days 86 400*3) to
// show whether the Time resets correctly.
//
// TODO: Complementary work needed: Submit your test cases as well.
//
// Comment: Generally the header guards are all capital letters, and is the
// filename with dots replaced with underscore, i.e TIME_H

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


