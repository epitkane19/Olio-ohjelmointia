#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <iostream>

using namespace std;


class Pankkitili
{
public:
    Pankkitili();
    Pankkitili(string omistaja);

    double getBalance();
    void setBalance();
    virtual bool deposit(double summa);
    virtual bool withdraw(double summa);

protected:
    string omistaja;
    double saldo = 0;

};

#endif // PANKKITILI_H
