#include "Components.h"
Resistor::Resistor(const std::string &name, double resistance, Connection &p, Connection &n) : Component(name, p, n), resistance(resistance)
{
    voltage = p.voltage - n.voltage;
}

void Resistor::simulate(double timeStep)
{
    voltage = positive.voltage - negative.voltage;

    double charge = (voltage / resistance) * timeStep;

    positive.voltage -= charge;

    negative.voltage += charge;
}

double Resistor::getVoltage() const
{
    return voltage;
}

double Resistor::getCurrent() const
{
    return voltage / resistance;
}
