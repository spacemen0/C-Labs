#include "Components.h"

Component::Component(const std::string &name, Connection &p, Connection &n) : name(name), positive(p), negative(n)
{
}
std::string Component::getName() const
{
    return name;
}
