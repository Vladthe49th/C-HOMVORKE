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
    list<unique_ptr<Person>> people; // List of ppl

public:
    void addPerson(unique_ptr<Person> person) {
        people.push_back(move(person));
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
        person->printInfo(); 
    }
};

int main() {
    School school;

    // Teachers, students, teachers, students
    auto student1 = make_unique<Student>("Alice", 10);
    auto student2 = make_unique<Student>("Bob", 12);
    auto teacher1 = make_unique<Teacher>("Mr. Smith", "Math");
    auto teacher2 = make_unique<Teacher>("Ms. Johnson", "Physics");

    // Go to school
    school.addPerson(move(student1));
    school.addPerson(move(student2));
    school.addPerson(move(teacher1));
    school.addPerson(move(teacher2));

    
    cout << "People in school:\n";
    school.printAllPeople();

    // Base class transform
    std::cout << "\nConverting Student to Person:\n";
    // Using raw pointer cause unique ptr can`t handle copying
    Student tempStudent("Temporary Student", 9);
    school.convertStudentToPerson(&tempStudent);

}


