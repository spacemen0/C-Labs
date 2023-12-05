#include "Components.h"
Battery::Battery(const std::string &name, double batteryVoltage, Connection &p, Connection &n) : Component(name, p, n)
{
    this->batteryVoltage = batteryVoltage;
}

void Battery::simulate(double timeStep)
{
    positive.voltage = batteryVoltage;

    negative.voltage = 0;

    voltage = batteryVoltage;
}

double Battery::getVoltage() const
{
    return voltage;
}

double Battery::getCurrent() const
{
    return current;
}
