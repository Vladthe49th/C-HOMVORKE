#include <iostream>
#include <string>
#include <memory> 
#include <list>   
using namespace std;

// Base person class
class Person {
protected:
    string name;

public:
    explicit Person(const string& name) : name(name) {}
    virtual ~Person() = default;

    virtual void printInfo() const {
        cout << "Name: " << name << endl;
    }
};

// Student class
class Student : public Person {
private:
    int grade;

public:
    Student(const string& name, int grade) : Person(name), grade(grade) {}

    void printInfo() const override {
        cout << "Student - Name: " << name << ", Grade: " << grade << endl;
    }
};

// Teacher
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(const string& name, const string& subject) : Person(name), subject(subject) {}

    void printInfo() const override {
        cout << "Teacher - Name: " << name << ", Subject: " << subject << endl;
    }
};

// School
class School {
private:
    list<shared_ptr<Person>> people; // Список людей
public:
    // Додавання учня або вчителя
    void addPerson(const shared_ptr<Person>& person) {
        people.push_back(person);
    }

    void printAllPeople() const {
        for (const auto& person : people) {
            if (dynamic_cast<Student*>(person.get())) {
                cout << "[Student] ";
            }
            else if (dynamic_cast<Teacher*>(person.get())) {
                cout << "[Teacher] ";
            }
            person->printInfo();
        }
    }

    void convertStudentToPerson(Student* student) {
        Person* person = static_cast<Person*>(student);
        person->printInfo(); // Демонстрація роботи
    }
};


int main() {
    School school;

    // Teachers, students, teachers, students
    auto student1 = make_shared<Student>("Gavrick", 10);
    auto student2 = make_shared<Student>("Lelik", 12);
    auto teacher1 = make_shared<Teacher>("Charlotte Ivanovna", "Math");
    auto teacher2 = make_shared<Teacher>("Jason Statham", "Physics");

    // Go to school
    school.addPerson(student1);
    school.addPerson(student2);
    school.addPerson(teacher1);
    school.addPerson(teacher2);


    cout << "People in school:\n";
    school.printAllPeople();

    // Base class transform
    Person* basePerson = static_cast<Person*>(student1.get());
    cout << "\nStudent as base class Person:\n";
    basePerson->printInfo();

}