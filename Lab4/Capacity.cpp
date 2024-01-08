#include "Components.h"

Capacitor::Capacitor(const std::string &name, double capacitance, Connection &p, Connection &n)
    : Component(name, p, n), capacitance(capacitance), storedCharge(0.0)
{
    // voltage = p - n;
}

void Capacitor::simulate(double timeStep)
{
    // voltage = ;
    double charge{capacitance * ((positive - negative) - (storedCharge)) * timeStep};
    positive -= charge;
    negative += charge;
    storedCharge += charge;
}

double Capacitor::getVoltage() const
{
    return positive - negative;
}

double Capacitor::getCurrent() const
{
    return capacitance * ((positive - negative) - storedCharge);
}
