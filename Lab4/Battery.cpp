#include "Components.h"
Battery::Battery(const std::string &name, double batteryVoltage, Connection &p, Connection &n) : Component(name, p, n), batteryVoltage(batteryVoltage)
{
}

void Battery::simulate(double timeStep)
{
    (void)timeStep;
    positive = batteryVoltage;
    negative = 0;
}

double Battery::getVoltage() const
{
    return batteryVoltage;
}

double Battery::getCurrent() const
{
    return 0;
}
