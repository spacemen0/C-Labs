#include "Components.h"

Component::Component() : name(""), positive(*(new Connection())), negative(*(new Connection()))
{
    voltage = 0;
    current = 0;
}
Component::Component(const std::string &name, Connection &p, Connection &n) : name(name), positive(p), negative(n)
{
    voltage = 0;
    current = 0;
}
std::string Component::getName() const
{
    return name;
}