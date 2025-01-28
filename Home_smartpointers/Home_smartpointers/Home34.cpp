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

// legacy student class
class Student : public Person {
private:
    int grade;

public:
    Student(const string& name, int grade) : Person(name), grade(grade) {}

    void printInfo() const override {
        cout << "Student - Name: " << name << ", Grade: " << grade << endl;
    }
};

// Legacy class teacher
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(const string& name, const string& subject) : Person(name), subject(subject) {}

    void printInfo() const override {
        cout << "Teacher - Name: " << name << ", Subject: " << subject << endl;
    }
};

// School class, agregating people
class School {
private:
    list<shared_ptr<Person>> people; // List of ppl in school

public:
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

    void convertStudentToPerson(const shared_ptr<Student>& student) {
        shared_ptr<Person> person = static_pointer_cast<Person>(student);
        person->printInfo(); 
    }
};

int main() {
    School school;

    // Let`s make some teachers/students
    shared_ptr<Student> student1 = make_shared<Student>("Gavrick", 10);
    shared_ptr<Student> student2 = make_shared<Student>("Lelik", 12);
    shared_ptr<Teacher> teacher1 = make_shared<Teacher>("Irina Alexandrovna", "Math");
    shared_ptr<Teacher> teacher2 = make_shared<Teacher>("Jason Statham", "Physics");

    // Add them to school
    school.addPerson(student1);
    school.addPerson(student2);
    school.addPerson(teacher1);
    school.addPerson(teacher2);

    // List of all ppl
    cout << "People in school:\n";
    school.printAllPeople();

    // Transforming to base class example
    cout << "\nConverting Student to Person:\n";
    school.convertStudentToPerson(student1);

}
