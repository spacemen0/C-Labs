#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include "Connection.h"

// TODO: Complementary work needed: Don’t keep unnecessary data members.
// (voltage, current)
//
class Component
{
public:
    Component();
    Component(const std::string &name, Connection &p, Connection &n);

    virtual ~Component() = default;

    virtual void simulate(double timeStep) = 0;
    virtual double getVoltage() const = 0;
    virtual double getCurrent() const = 0;
    std::string getName() const ;

protected:
    std::string name;
    Connection &positive;
    Connection &negative;
    double voltage;
    double current;
};

class Battery : public Component
{
public:
    Battery(const std::string &name, double batteryVoltage, Connection &p, Connection &n);
    void simulate(double timeStep) override;
    double getVoltage() const override;
    double getCurrent() const override;

private:
    double batteryVoltage;
};

class Resistor : public Component
{
public:
    Resistor(const std::string &name, double resistance, Connection &p, Connection &n);
    void simulate(double timeStep) override;
    double getVoltage() const override;
    double getCurrent() const override;

private:
    double resistance;
};

class Capacitor : public Component
{
public:
    Capacitor(const std::string &name, double capacitance, Connection &p, Connection &n);

    void simulate(double timeStep) override;
    double getVoltage() const override;
    double getCurrent() const override;

private:
    double capacitance;
    double storedCharge;
};
#endif
