#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

int main ()
{
    int selection =0;
    string n;
    string searched;
    vector<Student> studentList = { {"Aapo", 20}, {"Bertta", 21}, {"Caapo", 19} };

    studentList.push_back({"Daavid", 22});
    studentList.push_back({"Eerik", 25});

    do {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                // Lisää uusi student StudentList vektoriin.

                break;
            case 1:
                // Tulosta StudentList vektorin kaikkien opiskelijoiden
                // nimet.
                cout << "Students: " << endl;
                for(Student s: studentList) {
                    s.printStudentInfo();
                }
                break;

            case 2:
                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                    return a.getName() < b.getName();
                });

                cout << endl << "Sort by name:" << endl;
                for(Student s: studentList) {
                    s.printStudentInfo();
                }
                break;

            case 3:
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                sort(studentList.begin(), studentList.end());
                cout << endl << "Sort by age:" << endl;
                for(Student s: studentList) {
                    s.printStudentInfo();
                }

                break;
            case 4:
                // Kysy käyttäjältä opiskelijan nimi
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
                // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                cout << "Student to be found: ";
                cin >> n;
                for(Student s: studentList) {
                    s.setName(n);
                    searched = s.getName();
                    auto found = std::find_if(studentList.begin(), studentList.end(), [&searched](const Student& student) {
                        return student.getName() == searched;
                    });

                    if(found != studentList.end()) {
                        cout << "Found student: " << found->getName() << ", " << found->getAge() << endl;
                    }
                    else {
                        cout << "Student not found" << endl;
                    }
                    break;

                }
                break;

            default:
                cout<< "Wrong selection, stopping..."<<endl;
                break;
        }
    } while(selection < 5);

    return 0;
}

