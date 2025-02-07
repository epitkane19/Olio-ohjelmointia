#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {}

void Notifikaattori::lisaa(Seuraaja *uusi)
{
    uusi->next = seuraajat;
    seuraajat = uusi;
    cout << "Lisataan " << uusi->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja *poisto)
{
    if (seuraajat == poisto) {
        seuraajat = poisto->next;
        cout << "Poistetaan " << poisto->getNimi() << endl;
    }
    else {
        Seuraaja *alku = seuraajat;
        while(alku != nullptr) {
            if(alku->next == poisto) {
                alku->next = poisto->next;
                cout << "Poistetaan " << poisto->getNimi() << endl;
            }
            alku = alku->next;
        }
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        cout << "Notifikaattorin seuraajat: " << alku->getNimi() << endl;
        alku = alku->next;
    }
}

void Notifikaattori::postita(string v)
{
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        alku->paivitys(v);
        alku = alku->next;
    }
}



