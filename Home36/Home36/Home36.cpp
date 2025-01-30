#include <iostream>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

class Engine {
protected:
    string fuelType;
    int power;

public:
    Engine(const string& fuelType, int power)
        : fuelType(fuelType), power(power) {
    }

    virtual ~Engine() {}

    virtual void printDetails(ostream& os = cout) const {
        os << "Fuel type: " << fuelType << ", Power: " << power << " HP" << endl;
    }

    virtual string getType() const = 0;
};

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power) : Engine("Petrol", power) {}

    void printDetails(ostream& os = cout) const override {
        os << "Petrol Engine - ";
        Engine::printDetails(os);
    }

    string getType() const override {
        return "Petrol";
    }
};

class ElectricEngine : public Engine {
public:
    ElectricEngine(int power) : Engine("Electric", power) {}

    void printDetails(ostream& os = cout) const override {
        os << "Electric Engine - ";
        Engine::printDetails(os);
    }

    string getType() const override {
        return "Electric";
    }
};

class Car {
private:
    unique_ptr<Engine> engine;
    string name;
    int serialNumber;

public:
    Car(unique_ptr<Engine> engine, const string& name, int serialNumber)
        : engine(move(engine)), name(name), serialNumber(serialNumber) {
    }

    void printDetails(ostream& os = cout) const {
        os << "Car: " << name << ", Serial Number: " << serialNumber << endl;
        os << "Engine Details: ";
        engine->printDetails(os);
        os << "----------------------" << endl;
    }

    Engine* getEngine() const {
        return engine.get();
    }

    string getName() const { return name; }
    int getSerialNumber() const { return serialNumber; }
};

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
            cout << "Park is full. Drive away, or try to squeeze through" << endl;
            return false;
        }
    }

    void printCars(ostream& os = cout) const {
        for (int i = 0; i < carCount; ++i) {
            os << "Car #" << i + 1 << ":" << endl;
            cars[i]->printDetails(os);
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        printCars(file);
        file.close();
        cout << "Car park saved to " << filename << endl;
    }
};

int main() {
    Company company;

    company.addCar(new Car(make_unique<PetrolEngine>(150), "Toyota", 12345));
    company.addCar(new Car(make_unique<ElectricEngine>(200), "Tesla", 54321));
    company.addCar(new Car(make_unique<PetrolEngine>(180), "Honda", 11223));
    company.addCar(new Car(make_unique<ElectricEngine>(250), "Nissan", 33221));
    company.addCar(new Car(make_unique<PetrolEngine>(220), "Ford Mustang", 98765));

    cout << "Company Car Park:" << endl;
    company.printCars();

    company.saveToFile("car_park.txt");

}