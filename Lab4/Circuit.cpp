#include "Circuit.h"

// TODO: Complementary work needed: Break long lines (more than 100 characters)
// into multiple lines.
//
// TODO: Complementary work needed: Use '{...}' instead of '=' to initialize variables.
//

Circuit::Circuit(int iterations, int printInterval, double timeStep) : iterations(iterations), printInterval(printInterval), timeStep(timeStep)
{
}

void Circuit::addComponent(Component *c)
{
    components.push_back(c);
}

void Circuit::simulate() const
{
    for (int i{1}; i <= iterations; i++)

    {

        for (Component *component : components)

        {

            component->simulate(timeStep);

            if (i % (iterations / printInterval) == 0)

            {

                std::cout << std::setw(8) << std::fixed << std::setprecision(2)
                          << component->getVoltage() << std::setw(8) << component->getCurrent();
            }
        }

        if (i % (iterations / printInterval) == 0)

        {

            std::cout << std::endl;
        }
    }
}

void Circuit::printHeader() const
{
    for (Component *component : components)

    {

        std::cout << std::setw(16) << component->getName();
    }

    std::cout << std::endl;

    for (int i{0}; i < static_cast<int>(components.size()); i++)

    {

        std::cout << std::setw(8) << " volt" << std::setw(8) << "curr";
    }

    std::cout << std::endl;
}

Circuit::~Circuit()
{
    for (Component *component : components)
    {
        delete component;
    }
}
