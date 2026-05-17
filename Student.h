#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    int id;
    char name[50];
    int age;
    char course[50];

public:
    void input();
    void display() const;

    int getId() const;
};

#endif
