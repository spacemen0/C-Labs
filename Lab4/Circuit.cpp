#include "Circuit.h"

Circuit::Circuit() : iterations(0), printInterval(0), timeStep(0)
{
}

Circuit::Circuit(int iterations, int printInterval, double timeStep) : iterations(iterations), printInterval(printInterval), timeStep(timeStep)
{
}

void Circuit::addComponent(Component *c)
{
    components.push_back(c);
}

void Circuit::simulate()
{
    for (int i{1}; i <= iterations; i++)

    {

        for (Component *component : components)

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

void Circuit::printHeader()
{
    for (Component *component : components)

    {

        std::cout << std::setw(16) << component->getName();
    }

    std::cout << std::endl;

    for (Component *component : components)

    {

        std::cout << std::setw(8) << " volt" << std::setw(8) << "curr";
    }

    std::cout << std::endl;
}

void Circuit::deallocate_components()
{
    for (Component *component : components)
    {
        delete component;
    }
}
