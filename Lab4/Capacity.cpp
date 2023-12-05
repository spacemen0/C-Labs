#include "Components.h"
Capacitor::Capacitor(const std::string &name, double capacitance, Connection &p, Connection &n) : Component(name, p, n), capacitance(capacitance)
{
    storedCharge = 0.0;
    voltage = p.voltage - n.voltage;
}

void Capacitor::simulate(double timeStep)
{
    voltage = positive.voltage - negative.voltage;
    double charge = capacitance * ((voltage) - (storedCharge)) * timeStep;
    positive.voltage -= charge;
    negative.voltage += charge;
    storedCharge += charge;
}

double Capacitor::getVoltage() const
{
    return voltage;
}

double Capacitor::getCurrent() const
{
    return capacitance * (voltage - storedCharge);
}
