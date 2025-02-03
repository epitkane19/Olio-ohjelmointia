#include "luottotili.h"

using namespace std;

Luottotili::Luottotili(string omistaja, double luottoRaja) : Pankkitili(omistaja)
{
    //cout << "Luottoraja = " << luottoRaja << endl;
}

bool Luottotili::deposit(double summa)
{
    //cout << "velka = " << saldo << ", velanmaksu = " << summa << endl;
    if(summa < 0) {
        return false;
    }
    else {
        saldo = saldo - summa;
        if(saldo < 0)
            saldo = 0;
        //cout << "Velka: " << saldo << endl;
        return true;
    }
}

bool Luottotili::withdraw(double summa)
{
    //cout << "velka = " << saldo << ", nosto = " << summa << endl;
    if(summa < 0) {
        return false;
    }
    else if (saldo + summa > luottoRaja) {
        return false;
    }
    else {
        saldo = saldo + summa;
        //cout << "Velka: " << saldo << endl;
        return true;
    }
}

double Luottotili::getVelka()
{
    return saldo;
}

double Luottotili::getLuottoRaja()
{
    return luottoRaja;
}

void Luottotili::setLuottoRaja()
{
    cin >> luottoRaja;
}




