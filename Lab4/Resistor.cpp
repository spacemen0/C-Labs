#include "Components.h"
Resistor::Resistor(const std::string &name, double resistance, Connection &p, Connection &n) : Component(name, p, n), resistance(resistance)
{
    // voltage = p - n;
}

void Resistor::simulate(double timeStep)
{

    // double charge{((positive - negative) / resistance) * timeStep};

    // positive -= charge;

    // negative += charge;
}

double Resistor::getVoltage() const
{
    return positive - negative;
}

double Resistor::getCurrent() const
{
    return (positive - negative) / resistance;
}
