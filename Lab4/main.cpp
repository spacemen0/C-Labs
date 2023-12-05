#include <iostream>
#include <vector>
#include <iomanip>

// Forward declarations
class Connection;

// Base class for circuit components
class Component {
public:
    Component(const std::string& name, Connection& p, Connection& n) 
        : name{ name }, positive{ p }, negative{ n } {
        voltage = 0;
        current = 0;
    }//constructor
    virtual ~Component() = default;

    virtual void simulate(double timeStep) = 0;// pure-virtual function
    virtual double getVoltage() const = 0;// pure-virtual function
    virtual double getCurrent() const = 0;// pure-virtual function
    virtual std::string getName() const = 0;// pure-virtual function


protected:
    std::string name;
    Connection& positive;
    Connection& negative;
    double voltage;
    double current;
};

// Connection class for connecting terminals
class Connection {
public:
    Connection() : voltage(0.0) {}

    double voltage;
};

// Battery class
class Battery : public Component {
public:
    Battery(const std::string& name, double batteryVoltage, Connection& p, Connection& n)
        :Component(name, p, n), batteryVoltage(batteryVoltage) {

    }

    void simulate(double timeStep) override {
        positive.voltage = batteryVoltage;
        negative.voltage = 0;
        voltage = batteryVoltage;

    }
    double getVoltage() const override {
        return voltage;
    }
    double getCurrent() const override {
        return current;
    }
    std::string  getName() const override {
        return name;
    }

private:
    double batteryVoltage;
};

// Resistor class
class Resistor : public Component {
public:
    Resistor(const std::string& name, double resistance, Connection& p, Connection& n)
    :Component(name, p, n), resistance(resistance) {
        voltage = p.voltage - n.voltage;
    }

    void simulate(double timeStep) override {
        voltage = positive.voltage - negative.voltage;
        charge = (voltage / resistance) * timeStep;
        positive.voltage -= charge;
        negative.voltage += charge;

    }
    double getVoltage() const override {
        return voltage;
    }
    double getCurrent() const override {
        return voltage / resistance;
    }
    std::string  getName() const override {
        return name;
    }
private:
    double resistance;
    double charge;
};


class Capacitor : public Component {
public:
    Capacitor(const std::string& name, double capacitance, Connection& p, Connection& n)
        :Component(name, p, n), capacitance(capacitance) , storedCharge(0.0) {
        voltage = p.voltage - n.voltage;
    }

    void simulate(double timeStep) override {
        voltage = positive.voltage - negative.voltage;
        charge = capacitance * ((voltage)-(storedCharge)) * timeStep; //calculate charge to store
        positive.voltage -= charge;
        negative.voltage += charge;
        storedCharge += charge;

 
    }
    double getVoltage() const override {
        return voltage;
    }
    double getCurrent() const override {
        return capacitance*(voltage - storedCharge);
    }
    std::string  getName() const override {
        return name;
    }

private:
    double capacitance;
    double storedCharge;
    double charge;
};

// Function to simulate the circuit
void simulate(const std::vector<Component*>& circuit, int iterations, int printInterval, double timeStep) {

    for (int i{ 1 };i <= iterations;i++) {
        for (Component* component : circuit) {
            component->simulate(timeStep);
            
            if (i % (iterations / printInterval) == 0) {
                std::cout << std::setw(8)<< std::fixed << std::setprecision(2) << component->getVoltage() << std::setw(8) << component->getCurrent();
            }
        
        }
        if (i % (iterations / printInterval) == 0) {
          std::cout << std::endl;
          }
    }
}

// Function to deallocate components
void deallocate_components(const std::vector<Component*>& circuit) {
    for (Component* component : circuit) {
            delete component;
    }
}

int main(int argc, char* argv[]) {
    // Parse command line arguments and build circuits
    // ...
    /*Connection p, n, r124, r23;
    std::vector<Component*> net;
    net.push_back(new Battery("Bat", 24.0, p, n));
    net.push_back(new Resistor("R1", 6.0, p, r124));
    net.push_back(new Resistor("R2", 4.0, r124, r23));
    net.push_back(new Resistor("R3", 8.0, r23, n));
    net.push_back(new Resistor("R4", 12.0, r124, n));
    for (Component* component : net) {
        std::cout << std::setw(16) << component->getName();
    }
    std::cout << std::endl;
    for (Component* component : net) {
        std::cout << std::setw(8) << " Volt" << std::setw(8) << "Curr";
    }
    std::cout << std::endl;
    simulate(net, 10000, 10, 0.1);
    deallocate_components(net);*/
    
    /*Connection p, l, r, n;
    std::vector<Component*> net2;
    net2.push_back(new Battery("bat", 24.0, p, n));
    net2.push_back(new Resistor("r1", 150, p, l));
    net2.push_back(new Resistor("r2", 50, p, r));
    net2.push_back(new Resistor("r3", 100, r, l));
    net2.push_back(new Resistor("r4", 300, l, n));
    net2.push_back(new Resistor("r5", 250, r, n));
    for (Component* component : net2) {
        std::cout << std::setw(16) << component->getName();
    }
    std::cout << std::endl;
    for (Component* component : net2) {
        std::cout << std::setw(8) <<" volt" << std::setw(8) << "curr";
    }
    std::cout << std::endl;
    simulate(net2, 20000, 10, 0.1);
    deallocate_components(net2);*/

    Connection p, l, r, n;
    std::vector<Component*> net3;
    net3.push_back(new Battery("bat", 24.0, p, n));
    net3.push_back(new Resistor("r1", 150, p, l));
    net3.push_back(new Resistor("r2", 50, p, r));
    net3.push_back(new Capacitor("c3", 1.0, r, l));
    net3.push_back(new Resistor("r4", 300, l, n));
    net3.push_back(new Capacitor("c5", 0.75, r, n));
    for (Component* component : net3) {
        std::cout << std::setw(16) << component->getName();
    }
    std::cout << std::endl;
    for (Component* component : net3) {
        std::cout << std::setw(8) <<" volt" << std::setw(8) << "curr";
    }
    std::cout << std::endl;
    simulate(net3, 200000, 10, 0.01);
    //std::cout << p.voltage << "" << l.voltage << "" << r.voltage << "" << n.voltage;
    deallocate_components(net3);

    return 0;
}
