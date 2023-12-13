#include "Components.h"


// TODO: Complementary work needed: If someone happens to use the default
// constructor for Component, there will be a memory leak since nothing is
// implemented to clean up the memory allocated to the connections.

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
