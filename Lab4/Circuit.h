#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>
#include <iostream>
#include <iomanip>
#include "Components.h"

class Circuit
{
public:
    Circuit(int iterations, int printInterval, double timeStep);
    ~Circuit();
    void addComponent(Component *c);
    void simulate() const;
    void printHeader() const;

private:
    std::vector<Component *> components;
    int iterations;
    int printInterval;
    double timeStep;
};
#endif
