#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include <iostream>
#include "pankkitili.h"

using namespace std;

class Luottotili : public Pankkitili
{
public:
    Luottotili();
    Luottotili(string omistaja, double luottoRaja);

    virtual bool deposit(double summa) override;
    virtual bool withdraw(double summa) override;
    double getVelka();
    double getLuottoRaja();
    void setLuottoRaja();

protected:
    double luottoRaja = 0;

};


#endif // LUOTTOTILI_H
