#include <iostream>
#include <string>
#include <memory>
using namespace std;

//class Engine
class Engine {
protected:
    string fuelType;
    int power; // horse power

public:
    Engine(const string& fuelType, int power)
        : fuelType(fuelType), power(power) {
    }

    virtual ~Engine() {}

    virtual void printDetails() const {
        cout << "Fuel type: " << fuelType << ", Power: " << power << " HP" << endl;
    }
};

// Petrol engine
class PetrolEngine : public Engine {
public:
    PetrolEngine(int power) : Engine("Petrol", power) {}

    void printDetails() const override {
        cout << "Petrol Engine - ";
        Engine::printDetails();
    }
};


//Electric engine
class ElectricEngine : public Engine {
public:
    ElectricEngine(int power) : Engine("Electric", power) {}

    void printDetails() const override {
        cout << "Electric Engine - ";
        Engine::printDetails();
    }
};

// Car
class Car {
private:
    unique_ptr<Engine> engine;
    string name;
    int serialNumber;

public:
    Car(unique_ptr<Engine> engine, const string& name, int serialNumber)
        : engine(move(engine)), name(name), serialNumber(serialNumber) {
    }

    void printDetails() const {
        cout << "Car: " << name << ", Serial Number: " << serialNumber << std::endl;
        cout << "Engine Details: ";
        engine->printDetails();
    }

    Engine* getEngine() const {
        return engine.get();
    }
};

// Company
class Company {
private:
    Car* cars[5];
    int carCount;

public:
    Company() : carCount(0) {
        for (int i = 0; i < 5; ++i) {
            cars[i] = nullptr;
        }
    }

    ~Company() {
        for (int i = 0; i < carCount; ++i) {
            delete cars[i];
        }
    }

    bool addCar(Car* car) {
        if (carCount < 5) {
            cars[carCount++] = car;
            return true;
        }
        else {
            cout << "Park is full. Cannot add more cars." << endl;
            return false;
        }
    }

    void printCars() const {
        for (int i = 0; i < carCount; ++i) {
            cout << "Car #" << i + 1 << ":" << endl;
            cars[i]->printDetails();

            // Dynamic cast to check engine type
            if (dynamic_cast<PetrolEngine*>(cars[i]->getEngine())) {
                cout << "This is a Petrol Engine." << endl;
            }
            else if (dynamic_cast<ElectricEngine*>(cars[i]->getEngine())) {
                cout << "This is an Electric Engine." << endl;
            }

            // Static cast to base class
            Engine* baseEngine = static_cast<Engine*>(cars[i]->getEngine());
            std::cout << "Base Engine Details: ";
            baseEngine->printDetails();

            cout << "----------------------" << endl;
        }
    }
};

int main() {
    Company company;

    // Some cars
    company.addCar(new Car(std::make_unique<PetrolEngine>(150), "Toyota", 12345));
    company.addCar(new Car(std::make_unique<ElectricEngine>(200), "Tesla Model", 54321));
    company.addCar(new Car(std::make_unique<PetrolEngine>(180), "Honda", 11223));
    company.addCar(new Car(std::make_unique<ElectricEngine>(250), "Nissan", 33221));
    company.addCar(new Car(std::make_unique<PetrolEngine>(220), "Ford Mustang", 98765));

    // Auto info
    cout << "Company Car Park:" << endl;
    company.printCars();

}
