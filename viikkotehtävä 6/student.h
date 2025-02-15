#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student(string n, int a);
    void setAge(int a);
    void setName(string n);
    int getAge() const;
    string getName() const;
    void printStudentInfo();

    bool operator<(const Student& s) const {
        return age < s.age;
    }

private:
    string name;
    int age;
};

#endif // STUDENT_H
