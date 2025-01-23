#include <iostream>
#include <string>
#include <chef.h>



Chef::~Chef() {
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getName() {
    cout << "Anna nimi: ";
    cin >> chefName;
    return chefName;
}

int Chef::makeSalad(int ainekset) {
    salad = ainekset / 5;
    cout << "Chef " << chefName << " with " << ainekset << " items can make salad " << salad << " portions";
    return salad;
}

int Chef::makeSoup(int ainekset) {
    soup = ainekset / 3;
    cout << "Chef " << chefName << " with " << ainekset << " items can make soup " << soup << " portions" << endl;
    return soup;
}

ItalianChef::ItalianChef(string name) : Chef(name) {

}



bool ItalianChef::askSecret(string salasana) {
    bool running = true;
    do {
        cout << "Anna salasana: ";
        cin >> salasana;
        switch (salasana.compare(password)) {
        case 0:
            makePizza();
            running = false;
            break;
        default:
            cout << "Wrong password!" << endl;
            running = true;
        }
    } while (!cin.eof() && running);
    return 0;
}

int ItalianChef::makePizza() {
    cout << "Anna veden määrä: ";
    cin >> water;
    cout << "Anna jauhojen määrä: ";
    cin >> flour;
    int num1 = water / 5;
    int num2 = flour / 5;
    pizza = min(num1,num2);
    cout << "Chef " << chefName << " with " << flour << " flour and " << water << " water can make " << pizza << " pizzas" << endl;
    return pizza;
}
