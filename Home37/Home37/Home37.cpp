#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {}
    virtual ~Vehicle() = default;
    virtual void DisplayInfo() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year;
    }
    string GetBrand() const { return brand; }
};

class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;
public:
    Car(string b, string m, int y, int doors, string fuel)
        : Vehicle(b, m, y), numberOfDoors(doors), fuelType(fuel) {
    }
    void DisplayInfo() const override {
        Vehicle::DisplayInfo();
        cout << ", Doors: " << numberOfDoors << ", Fuel: " << fuelType << endl;
    }
};

class Truck : public Vehicle {
    double loadCapacity;
    int axleCount;
public:
    Truck(string b, string m, int y, double capacity, int axles)
        : Vehicle(b, m, y), loadCapacity(capacity), axleCount(axles) {
    }
    void DisplayInfo() const override {
        Vehicle::DisplayInfo();
        cout << ", Load Capacity: " << loadCapacity << " tons, Axles: " << axleCount << endl;
    }
};

class Motorcycle : public Vehicle {
    double engineVolume;
public:
    Motorcycle(string b, string m, int y, double volume)
        : Vehicle(b, m, y), engineVolume(volume) {
    }
    void DisplayInfo() const override {
        Vehicle::DisplayInfo();
        cout << ", Engine Volume: " << engineVolume << "L" << endl;
    }
};

class FleetManager {
    vector<unique_ptr<Vehicle>> vehicles;
public:
    void AddVehicle(unique_ptr<Vehicle> vehicle) {
        vehicles.push_back(move(vehicle));
    }

    void RemoveVehicle(const string& brand) {
        vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(), [&](const unique_ptr<Vehicle>& v) {
            return v->GetBrand() == brand;
            }), vehicles.end());
    }

    void ShowAllVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle->DisplayInfo();
        }
    }

    void SearchByBrand(const string& brand) const {
        for (const auto& vehicle : vehicles) {
            if (vehicle->GetBrand() == brand) {
                vehicle->DisplayInfo();
            }
        }
    }
};

int main() {
    FleetManager fleet;

    fleet.AddVehicle(make_unique<Car>("Toyota", "Camry", 2020, 4, "Petrol"));
    fleet.AddVehicle(make_unique<Truck>("Volvo", "FH16", 2019, 20.5, 4));
    fleet.AddVehicle(make_unique<Motorcycle>("Harley-Davidson", "Street 750", 2021, 0.75));

    cout << "All Vehicles in Fleet:\n";
    fleet.ShowAllVehicles();

    cout << "\nSearching for 'Toyota':\n";
    fleet.SearchByBrand("Toyota");

    fleet.RemoveVehicle("Toyota");
    cout << "\nAfter removing Toyota:\n";
    fleet.ShowAllVehicles();

}
