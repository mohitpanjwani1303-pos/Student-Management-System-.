#include "FileHandler.h"
#include "Student.h"

#include <fstream>
#include <cstdio>

using namespace std;

// Add Student
void addStudent() {
    Student s;

    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "Student added successfully!\n";
}

// Display All Students
void displayStudents() {
    Student s;

    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found.\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }

    file.close();
}

// Search Student
void searchStudent() {
    Student s;
    int id;
    bool found = false;

    ifstream file("students.dat", ios::binary);

    cout << "Enter ID to search: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getId() == id) {
            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    file.close();
}

// Update Student
void updateStudent() {
    Student s;
    int id;
    bool found = false;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    cout << "Enter ID to update: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getId() == id) {

            cout << "Enter new details:\n";
            s.input();

            int pos = -1 * sizeof(s);

            file.seekp(pos, ios::cur);
            file.write((char*)&s, sizeof(s));

            cout << "Record updated successfully!\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    file.close();
}

// Delete Student
void deleteStudent() {
    Student s;
    int id;
    bool found = false;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    cout << "Enter ID to delete: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {

        if (s.getId() == id) {
            found = true;
        }
        else {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Record deleted successfully!\n";
    else
        cout << "Student not found.\n";
}
