#include "Student.h"

Student::Student(string n, int a) {
    name = n;
    age = a;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setName(string n)
{
    name = n;
}

int Student::getAge() const
{
    return age;
}

string Student::getName() const
{
    return name;
}

void Student::printStudentInfo()
{
    cout << getName() << ", " << getAge() << endl;
}

