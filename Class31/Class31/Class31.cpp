#include <iostream>
#include <string>
#include <list>

using namespace std;

// Engine class
class Engine {
    double volume;
    string fuelType;
    int horsepower;

public:
    Engine(double vol, string fuel, int hp) : volume(vol), fuelType(fuel), horsepower(hp) {}

    double getVolume() const { return volume; }
    string getFuelType() const { return fuelType; }
    int getPower() const { return horsepower; }

    void display() const {
        cout << "Engine: " << volume << "L, " << fuelType << ", " << horsepower << " HP" << endl;
    }

    
};

// Class for Transmission
class Transmission {
    string type;

public:
    Transmission(const string& type) : type(type) {}

    string getType() const { return type; }

    void display() const {
        cout << "Transmission: " << type << endl;
    }
};

// Base class for Vehicle
class Vehicle {
protected:
    string typeVehicle;
    string brand;
    string model;
    int year;
    double price;
    Engine engine;
    Transmission transmission;

public:
    Vehicle(const string& type, const string& brand, const string& model, int year, double price, const Engine& eng, const Transmission& trans)
        : typeVehicle(type), brand(brand), model(model), year(year), price(price), engine(eng), transmission(trans) {
    }

    string getTypeVehicle() const { return typeVehicle; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    virtual void displayDetails() const {
        cout << "Vehicle Type: " << typeVehicle << "\nBrand: " << brand << "\nModel: " << model << "\nYear: " << year << "\nPrice: $" << price << endl;
        engine.display();
        transmission.display();
    }

    virtual ~Vehicle() = default;
};

// Derived classes
class Sedan : public Vehicle {
    bool hasSunroof;

public:
    Sedan(const string& brand, const string& model, int year, double price, const Engine& eng, const Transmission& trans, bool sunroof)
        : Vehicle("Sedan", brand, model, year, price, eng, trans), hasSunroof(sunroof) {
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
    float loadCapacity;

public:
    Truck(const string& brand, const string& model, int year, double price, const Engine& eng, const Transmission& trans, float capacity)
        : Vehicle("Truck", brand, model, year, price, eng, trans), loadCapacity(capacity) {
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

class Motorcycle : public Vehicle {
    double fuelConsumption;

public:
    Motorcycle(const string& brand, const string& model, int year, double price, const Engine& eng, const Transmission& trans, double consumption)
        : Vehicle("Motorcycle", brand, model, year, price, eng, trans), fuelConsumption(consumption) {
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Fuel Consumption: " << fuelConsumption << " L/100km" << endl;
    }
};

class Moped : public Vehicle {
    double maxSpeed;

public:
    Moped(const string& brand, const string& model, int year, double price, const Engine& eng, const Transmission& trans, double speed)
        : Vehicle("Moped", brand, model, year, price, eng, trans), maxSpeed(speed) {
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
};

// Search Functions
void SearchByType(const list<Vehicle*>& vehicles, const string& type) {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getTypeVehicle() == type) {
            vehicle->displayDetails();
            cout << endl;
        }
    }
}

void SearchByYearProd(const list<Vehicle*>& vehicles, int year) {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getYear() == year) {
            vehicle->displayDetails();
            cout << endl;
        }
    }
}

void SearchByPrice(const list<Vehicle*>& vehicles, double minPrice, double maxPrice) {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getPrice() >= minPrice && vehicle->getPrice() <= maxPrice) {
            vehicle->displayDetails();
            cout << endl;
        }
    }
}

void SearchBySeveralParameters(const list<Vehicle*>& vehicles, const string& brand, const string& model, int year) {
    for (const auto& vehicle : vehicles) {
        if (vehicle->getBrand() == brand && vehicle->getModel() == model && vehicle->getYear() == year) {
            vehicle->displayDetails();
            cout << endl;
        }
    }
}

int main() {
    list<Vehicle*> vehicles;

    vehicles.push_back(new Sedan("Toyota", "Camry", 2020, 30000, Engine(2.5, "Gasoline", 203), Transmission("Automatic"), true));
    vehicles.push_back(new Truck("Ford", "F-150", 2019, 45000, Engine(3.5, "Diesel", 250), Transmission("Manual"), 5.0));
    vehicles.push_back(new Motorcycle("Yamaha", "MT-07", 2021, 7500, Engine(0.7, "Gasoline", 74), Transmission("Manual"), 4.5));
    vehicles.push_back(new Moped("Honda", "Dio", 2022, 1200, Engine(0.1, "Gasoline", 8), Transmission("Automatic"), 80.0));

    cout << "Searching for all Sedans:\n";
    SearchByType(vehicles, "Sedan");

    cout << "Searching for vehicles from 2021:\n";
    SearchByYearProd(vehicles, 2021);

    cout << "Searching for vehicles priced between $1000 and $10000:\n";
    SearchByPrice(vehicles, 1000, 10000);

    cout << "Searching for a specific vehicle (Brand: Yamaha, Model: MT-07, Year: 2021):\n";
    SearchBySeveralParameters(vehicles, "Yamaha", "MT-07", 2021);

    for (auto vehicle : vehicles) {
        delete vehicle;
    }
}
