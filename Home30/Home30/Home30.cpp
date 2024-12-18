#include <iostream>
#include <iomanip> // for precision setting
using namespace std;

// base shape class
class Shape {
public:
    // area method
    virtual double CalculateArea() const = 0;

    // Info print
    virtual void Print() const = 0;

    // Destroyah, but virtual
    virtual ~Shape() {}
};

// Rectangle descent
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double CalculateArea() const override {
        return length * width;
    }

    void Print() const override {
        cout << "Rectangle: length = " << length << ", width = " << width
            << ", area = " << CalculateArea() << endl;
    }
};

// Circle descent
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double CalculateArea() const override {
        return 3.14 * radius * radius;
    }

    void Print() const override {
        cout << "Circle: radius = " << radius
            << ", area = " << CalculateArea() << endl;
    }
};

// Triangle descent
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double CalculateArea() const override {
        return 0.5 * base * height;
    }

    void Print() const override {
        cout << "Triangle: base = " << base << ", height = " << height
            << ", area = " << CalculateArea() << endl;
    }
};



///////////

// Base animal class
class Animal {
public:
    virtual void MakeSound() const = 0; // method
    virtual void PrintInfo() const = 0; // method
    virtual ~Animal() {} // killer
};

//  Dog
class Dog : public Animal {
public:
    void MakeSound() const override {
        cout << "Гав!" << endl;
    }
    void PrintInfo() const override {
        cout << "Це собака." << endl;
    }
};

// Cat
class Cat : public Animal {
public:
    void MakeSound() const override {
        cout << "Мяу!" << endl;
    }
    void PrintInfo() const override {
        cout << "Це кіт." << endl;
    }
};

// Hippo
class Hippo : public Animal {
public:
    void MakeSound() const override {
        cout << "Пук среньк!" << endl;
    }
    void PrintInfo() const override {
        cout << "Це бегемот." << endl;
    }
};


// Base account class
class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual ~Account() {} // destroyyya

    virtual void CalculateInterest() = 0; // virtual function

    void Deposit(double amount) {
       
       balance += amount;
       cout << "Deposited: " << amount << ", New balance: " << balance << endl;
        
        
    }

    

    double GetBalance() const { return balance; }
    virtual void PrintInfo() const = 0; // Info method
};

// Account savings class
class SavingsAccount : public Account {
private:
    static constexpr double interestRate = 0.05; // 5% interest rate
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {}

    void CalculateInterest() override {
        balance += balance * interestRate;
        cout << "Interest added (5%); new balance: " << balance << endl;
    }

    void PrintInfo() const override {
        cout << "Account savings balance: " << balance << endl;
    }
};

// CheckingAccount class
class CheckingAccount : public Account {
private:
    static constexpr double serviceFeeRate = 0.02; // 2% comission
public:
    CheckingAccount(double initialBalance) : Account(initialBalance) {}

    void CalculateInterest() override {
        double serviceFee = balance * serviceFeeRate;
        balance -= serviceFee;
        cout << "Service fee deducted (2%): New balance: " << balance << endl;
    }

    void PrintInfo() const override {
        cout << "CheckingAccount Balance: " << balance << endl;
    }
};

//  Fixed deposit account class
class FixedDepositAccount : public Account {
private:
    static constexpr double interestRate = 0.1; // 10% interest
public:
    FixedDepositAccount(double initialBalance) : Account(initialBalance) {}

    void CalculateInterest() override {
        balance += balance * interestRate;
        cout << "Interest added (10%): New balance: " << balance << endl;
    }

   
    void PrintInfo() const override {
        cout << "Fixed deposit account balance: " << balance << endl;
    }
};


int main() {

    cout << "Task 1: " << endl;
    // Pointer array
    const int size = 3; // Кількість фігур
    Shape* shapes[size];

    // Here, have a load of figures:
    shapes[0] = new Rectangle(5, 3);
    shapes[1] = new Circle(4);
    shapes[2] = new Triangle(6, 4);

    // Calling for everyone
    for (int i = 0; i < size; ++i) {
        shapes[i]->Print();
    }

    // Free sum memory
    for (int i = 0; i < size; ++i) {
        delete shapes[i];
    }

    cout << endl;

    cout << "Task 2: " << endl;

    const int NUM_ANIMALS = 3; // getting animals for out list
    Animal* zoo[NUM_ANIMALS];  // array of pointers

    // Our animals
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Hippo();

    // Calling everyone
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        zoo[i]->MakeSound();
        zoo[i]->PrintInfo();
    }

    // free memory
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        delete zoo[i];
    }

    cout << endl;

    cout << "Task 3: " << endl;

    // Pointer array
        const int numAccounts = 3;
    Account* accounts[numAccounts] = {
        new SavingsAccount(1000.0),        
        new CheckingAccount(2000.0),       
        new FixedDepositAccount(5000.0)    
    };

    cout << fixed << setprecision(2); // Formatting of numbers

    // Поповнення рахунків
    cout << "\n--- Depositing Money ---\n";
    for (int i = 0; i < numAccounts; ++i) {
        accounts[i]->Deposit(500.0); // Give everyone 500 bucks
    }

    // Calculating percents
    cout << "\n Calculating Interest/Fees: \n";
    for (int i = 0; i < numAccounts; ++i) {
        accounts[i]->CalculateInterest();
    }

    // The final balance is...
    cout << "\n The final balance is... \n";
    for (int i = 0; i < numAccounts; ++i) {
        accounts[i]->PrintInfo();
    }

    // Memory shall be freer
    for (int i = 0; i < numAccounts; ++i) {
        delete accounts[i];
    }


}
