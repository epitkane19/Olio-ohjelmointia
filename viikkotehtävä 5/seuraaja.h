#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <iostream>
#include <string>

using namespace std;

class Seuraaja
{
public:
    Seuraaja(string n);
    string getNimi() const;
    void paivitys(string viesti);

    Seuraaja *next = nullptr;

private:
    string nimi;
};

#endif // SEURAAJA_H
