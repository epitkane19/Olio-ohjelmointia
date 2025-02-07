#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "seuraaja.h"


class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *uusi);
    void poista(Seuraaja *poisto);
    void tulosta();
    void postita(string v);

private:
    Seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
