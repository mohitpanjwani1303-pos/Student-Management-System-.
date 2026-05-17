#include "Student.h"
#include <cstring>

void Student::input() {
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(name, 50);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Course: ";
    cin.getline(course, 50);
}

void Student::display() const {
    cout << "\nID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Course: " << course << endl;
    cout << "--------------------------\n";
}

int Student::getId() const {
    return id;
}
