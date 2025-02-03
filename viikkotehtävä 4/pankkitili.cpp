#include <iostream>
#include "pankkitili.h"

using namespace std;

Pankkitili::Pankkitili(string) {

}

double Pankkitili::getBalance()
{
    return saldo;
}

void Pankkitili::setBalance()
{
    cin >> saldo;
}

bool Pankkitili::deposit(double summa)
{
    //cout << "saldo = " << saldo << ", talletus = " << summa << endl;
    if(summa < 0) {
        return false;
    }
    else {
        saldo = saldo + summa;
        //cout << "saldo = " << saldo << endl;
        return true;
    }

}

bool Pankkitili::withdraw(double summa)
{
    //cout << "saldo = " << saldo << ", nosto = " << summa << endl;
    if(summa < 0) {
        return false;
    }
    else if(summa > saldo) {
        return false;
    }
    else {
        saldo = saldo - summa;
        //cout << "saldo = " << saldo << endl;
        return true;
    }
}
