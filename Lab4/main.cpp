﻿#include "Circuit.h"
#include "Connection.h"
#include "Components.h"

template <typename T>
T convertArgument(const char *arg, const char *argName)
{
    try
    {
        return std::stod(arg);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: Invalid input for " << argName << std::endl;
        exit(1);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: Value of " << argName << " out of range" << std::endl;
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Error: Invalid number of command line arguments. Expected 4 arguments." << std::endl;
        return 1;
    }

    int iterations = convertArgument<int>(argv[1], "iterations");
    int printLines = convertArgument<int>(argv[2], "printLines");
    double timeStep = convertArgument<double>(argv[3], "timeStep");
    double batteryVoltage = convertArgument<double>(argv[4], "batteryVoltage");

    {
        Connection p, l, r, n;
        Circuit net1(iterations, printLines, timeStep);
        net1.addComponent(new Battery("Bat", batteryVoltage, p, n));
        net1.addComponent(new Resistor("R1", 6, p, l));
        net1.addComponent(new Resistor("R2", 4, l, r));
        net1.addComponent(new Resistor("R3", 8, r, n));
        net1.addComponent(new Resistor("R4", 12, l, n));
        net1.printHeader();
        net1.simulate();
        net1.deallocate_components();
    }
    {
        Connection p, l, r, n;
        Circuit net2(iterations, printLines, timeStep);
        net2.addComponent(new Battery("Bat", batteryVoltage, p, n));
        net2.addComponent(new Resistor("R1", 150, p, l));
        net2.addComponent(new Resistor("R2", 50, p, r));
        net2.addComponent(new Resistor("R3", 100, r, l));
        net2.addComponent(new Resistor("R4", 300, l, n));
        net2.addComponent(new Resistor("R5", 250, r, n));
        net2.printHeader();
        net2.simulate();
        net2.deallocate_components();
    }
    {
        Connection p, l, r, n;
        Circuit net3(iterations, printLines, timeStep);
        net3.addComponent(new Battery("Bat", batteryVoltage, p, n));
        net3.addComponent(new Resistor("R1", 150, p, l));
        net3.addComponent(new Resistor("R2", 50, p, r));
        net3.addComponent(new Capacitor("C3", 1.0, r, l));
        net3.addComponent(new Resistor("R4", 300, l, n));
        net3.addComponent(new Capacitor("C5", 0.75, r, n));
        net3.printHeader();
        net3.simulate();
        net3.deallocate_components();
    }

    return 0;
}