#include "asiakas.h"
#include "pankkitili.h"
#include "luottotili.h"
#include <iostream>

Asiakas::Asiakas(string nimi, double luottoRaja) : kayttotili(nimi), luottotili(nimi, luottoRaja)
{

}

bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return kayttotili.withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
}

void Asiakas::showSaldo()
{
    cout << "Asiakas: " << nimi << endl;
    cout << "Käyttötilin saldo: " << kayttotili.getBalance() << endl;
    cout << "Luottotilin velka: " << luottotili.getBalance() << endl;
    cout << "Luottotilin luottoraja: " << luottotili.getLuottoRaja() << endl;
}

void Asiakas::setSaldo()
{
    kayttotili.setBalance();
}

void Asiakas::setVelka()
{
    double saldo = luottotili.getBalance();
}

void Asiakas::setLuottoRaja()
{
    luottotili.setLuottoRaja();
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::setNimi()
{
    cout << "Anna asiakkaan nimi: ";
    cin >> nimi;
}

bool Asiakas::tiliSiirto(double summa, Asiakas &saaja)
{
    bool onnistui = kayttotili.withdraw(summa);
    if(onnistui) {
        saaja.talletus(summa);
        return true;
    }
    else {
        cout << "Siirto epäonnistui" << endl;
        return false;
    }
}




