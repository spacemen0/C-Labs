#include <iostream>
#include <iomanip>
#include <vector>
#include "Components.h"

void simulate(const std::vector<Component *> &circuit, int iterations, int printInterval, double timeStep)

{

    for (int i{1}; i <= iterations; i++)

    {

        for (Component *component : circuit)

        {

            component->simulate(timeStep);

            if (i % (iterations / printInterval) == 0)

            {

                std::cout << std::setw(8) << std::fixed << std::setprecision(2) << component->getVoltage() << std::setw(8) << component->getCurrent();
            }
        }

        if (i % (iterations / printInterval) == 0)

        {

            std::cout << std::endl;
        }
    }
}

// Function to deallocate components

void deallocate_components(const std::vector<Component *> &circuit)

{

    for (Component *component : circuit)

    {

        delete component;
    }
}

int main(int argc, char *argv[])

{

    Connection p, l, r, n;

    std::vector<Component *> net3;

    net3.push_back(new Battery("bat", 24.0, p, n));

    net3.push_back(new Resistor("r1", 150, p, l));

    net3.push_back(new Resistor("r2", 50, p, r));

    net3.push_back(new Capacitor("c3", 1.0, r, l));

    net3.push_back(new Resistor("r4", 300, l, n));

    net3.push_back(new Capacitor("c5", 0.75, r, n));

    for (Component *component : net3)

    {

        std::cout << std::setw(16) << component->getName();
    }

    std::cout << std::endl;

    for (Component *component : net3)

    {

        std::cout << std::setw(8) << " volt" << std::setw(8) << "curr";
    }

    std::cout << std::endl;

    simulate(net3, 200000, 10, 0.01);

    // std::cout << p.voltage << "" << l.voltage << "" << r.voltage << "" << n.voltage;

    deallocate_components(net3);

    return 0;
}