#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Customer;

class RoomBooking {
private:
    int roomNumber;
    int* daysBooked;
    std::size_t daysCount;
    Customer* customer;

public:
    // Default const.
    RoomBooking() : roomNumber(0), daysBooked(nullptr), daysCount(0), customer(nullptr) {}

    // Const. with parameters
    RoomBooking(int roomNum, const int* days, std::size_t count, Customer* cust)
        : roomNumber(roomNum), daysCount(count), customer(cust) {
        daysBooked = new int[daysCount];
        copy(days, days + daysCount, daysBooked);
    }

    // Copying const.
    RoomBooking(const RoomBooking& other)
        : roomNumber(other.roomNumber), daysCount(other.daysCount), customer(other.customer) {
        daysBooked = new int[daysCount];
        std::copy(other.daysBooked, other.daysBooked + daysCount, daysBooked);
    }

    // Movement const.
    RoomBooking(RoomBooking&& other) noexcept
        : roomNumber(other.roomNumber), daysBooked(other.daysBooked), daysCount(other.daysCount), customer(other.customer) {
        other.daysBooked = nullptr;
        other.daysCount = 0;
        other.customer = nullptr;
    }

    // Destroyer
    ~RoomBooking() {
        delete[] daysBooked;
    }

    // Alignment operator (copying)
    RoomBooking& operator=(const RoomBooking& other) {
        if (this == &other) return *this;

        delete[] daysBooked;

        roomNumber = other.roomNumber;
        daysCount = other.daysCount;
        customer = other.customer;
        daysBooked = new int[daysCount];
        std::copy(other.daysBooked, other.daysBooked + daysCount, daysBooked);

        return *this;
    }

    // Alignment oper. (movement)
    RoomBooking& operator=(RoomBooking&& other) noexcept {
        if (this == &other) return *this;

        delete[] daysBooked;

        roomNumber = other.roomNumber;
        daysBooked = other.daysBooked;
        daysCount = other.daysCount;
        customer = other.customer;

        other.daysBooked = nullptr;
        other.daysCount = 0;
        other.customer = nullptr;

        return *this;
    }

    // Operator + for booking combinement
    RoomBooking operator+(const RoomBooking& other) const {
        if (customer != other.customer) {
            throw invalid_argument("Bookings must belong to the same customer.");
        }

        std::size_t newCount = daysCount + other.daysCount;
        int* newDays = new int[newCount];

        copy(daysBooked, daysBooked + daysCount, newDays);
        copy(other.daysBooked, other.daysBooked + other.daysCount, newDays + daysCount);

        RoomBooking newBooking(roomNumber, newDays, newCount, customer);
        delete[] newDays;

        return newBooking;
    }

    // Add day
    void addDay(int day) {
        int* newDays = new int[daysCount + 1];
        copy(daysBooked, daysBooked + daysCount, newDays);
        newDays[daysCount] = day;
        ++daysCount;

        delete[] daysBooked;
        daysBooked = newDays;
    }

    // Delete day
    void removeDay(int day) {
        auto it = find(daysBooked, daysBooked + daysCount, day);
        if (it != daysBooked + daysCount) {
            copy(it + 1, daysBooked + daysCount, it);
            --daysCount;
        }
    }

    // Booking info
    void printBooking() const {
        cout << "Room Number: " << roomNumber << "\nDays Booked: ";
        for (std::size_t i = 0; i < daysCount; ++i) {
            cout << daysBooked[i] << " ";
        }
        cout << "\n";
    }

    // << Operator for display
    friend ostream& operator<<(ostream& os, const RoomBooking& booking) {
        os << "Room Number: " << booking.roomNumber << ", Days Booked: [";
        for (std::size_t i = 0; i < booking.daysCount; ++i) {
            os << booking.daysBooked[i] << (i < booking.daysCount - 1 ? ", " : "");
        }
        os << "]";
        return os;
    }
};

class Customer {
private:
    string name;
    int customerID;
    RoomBooking* currentBooking;

public:


    // Comst. with parameters
    Customer(string custName, int custID)
        : name(custName), customerID(custID), currentBooking(nullptr) {
    }


    // Destroyer
    ~Customer() {
        delete currentBooking;
    }

    // Booking creation
    void makeBooking(RoomBooking* booking) {
        currentBooking = booking;
    }

    // Cancel booking
    void cancelBooking() {
        delete currentBooking;
    }

    // Client info
    void printCustomerInfo() const {
        cout << "Customer Name: " << name << "\nCustomer ID: " << customerID << "\n";
        if (currentBooking) {
            currentBooking->printBooking();
        }
        else {
            cout << "No current booking.\n";
        }
    }

    // << display oper
    friend ostream& operator<<(ostream& os, const Customer& customer) {
        os << "Customer Name: " << customer.name << ", ID: " << customer.customerID;
        if (customer.currentBooking) {
            os << ", Booking: " << *customer.currentBooking;
        }
        else {
            os << ", No current booking.";
        }
        return os;
    }
};

