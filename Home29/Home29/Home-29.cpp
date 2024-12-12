#include <iostream>
#include <string>
using namespace std;


// Base Person class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) : name(name), age(age) {}

    // Get info method
    virtual string getInfo() const {
        return "Name: " + name + ", Age: " + to_string(age);
    }

    // Destroro
    virtual ~Person() {}
};

// Sub class Car
class Child : public Person {
private:
    string parentName;

public:
    // Lego
    Child(string name, int age, string parentName) : Person(name, age), parentName(parentName) {}

    // Rearranging getInfo()
    string getInfo() const override {
        return Person::getInfo() + ", Parent: " + parentName;
    }
};


// Base Vehicle class

class Vehicle {
protected:
    string brand;
    int year;
public:
    // Playmobil
    Vehicle(string brand, int year) : brand(brand), year(year) {}

    virtual string GetDesc() const {
        return "Brand: " + brand + ", Year of creation: " + to_string(year);
    }

    virtual ~Vehicle() {}
};

// Sub class Car

class Car : public Vehicle {
private:
    string model;
    int mileage;
public:
    // Constructor
    Car(string brand, int year, string model, int mileage) : Vehicle(brand, year), model(model), mileage(mileage) {}

    // Getdesc rearrange

    string GetDesc() const override {
        return Vehicle::GetDesc() + ", model: " + model + ", and mileage: " + to_string(mileage);
    }
};

// Base class Employee

class Employee {
protected:
    string name;
    string position;
    double salary;
public:
    //Constr.
    Employee(string name, string position, double salary) : name(name), position(position), salary(salary) {}

    // Get details
    virtual string GetDetails() const {
        return "Name: " + name + ", position: " + position + ", salary: " + to_string(salary);
    }

    virtual ~Employee() {}
};

// Sub class Manager
class Manager : public Employee {
private: 
    string department;
public:
    Manager(string name, string position, double salary, string department) : 
        Employee(name, position, salary), department(department) {}

    //rearranging get details
    string GetDetails() const override {
        return Employee::GetDetails() + ", and department: " + department;
    }
};

int main() {

    cout << "Task 1: " << endl;
    // Person
    Person person("Ksenia", 30);
    cout << person.getInfo() << endl;

    // Child
    Child child("Billie", 10, "Jean");
    cout << child.getInfo() << endl;

    cout << endl;

    cout << "Task 2: " << endl;

    //Vehicle
    Vehicle vehicle("Toyota", 2001);
    cout << vehicle.GetDesc() << endl;

    //Car

    Car car("Ford", 2001, "X-14", 150);
    cout << car.GetDesc() << endl;

    cout << endl;

    cout << "Task 3: " << endl;

    //Employee
    Employee employee("Oleg", "svarshik", 15000.0);
    cout << employee.GetDetails()<< endl;

    //Manager
    Manager manager("Vladik", "manager", 40000.0, "Liteiny zavod");
    cout << manager.GetDetails() << endl;


}
