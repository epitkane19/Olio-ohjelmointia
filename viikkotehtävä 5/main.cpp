#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori *N = new Notifikaattori();

    //unique_ptr<Seuraaja> A(new Seuraaja("Aapo"); <- smart pointer
    Seuraaja *A = new Seuraaja("Aapo");
    Seuraaja *B = new Seuraaja("Bertta");
    Seuraaja *C = new Seuraaja("Caapo");
    cout << endl;

    N->lisaa(A);
    N->lisaa(B);
    N->lisaa(C);
    cout << endl;

    N->tulosta();
    cout << endl;

    N->postita("Test");
    cout << endl;

    N->poista(B);
    cout << endl;

    N->postita("Test2");
    cout << endl;

    N->poista(C);
    cout << endl;

    N->postita("Test3");
    cout << endl;

    N->lisaa(B);
    cout << endl;

    N->tulosta();
    cout << endl;

    delete A;
    delete B;
    delete C;

    return 0;
}
