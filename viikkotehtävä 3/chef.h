#ifndef CHEF_H
#define CHEF_H

#include <iostream>

using namespace std;

class Chef
{
public:
    Chef(string name) : chefName(name) {
        cout << "Chef " << chefName << " konstruktori" << endl;
    }
    ~Chef();

    string getName();
    int makeSalad(int ainekset);
    int makeSoup(int ainekset);

private:
    int salad;
    int soup;

protected:
    string chefName;
};

class ItalianChef : public Chef
{
public:
    ItalianChef(string name);
    ~ItalianChef() {

    }

    bool askSecret(string salasana);

private:
    string password = "pizza";
    int flour;
    int water;
    int pizza;

    int makePizza();
};

#endif // CHEF_H
