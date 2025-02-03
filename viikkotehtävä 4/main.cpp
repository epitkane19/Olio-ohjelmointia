#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

using namespace std;

int main()
{

    cout << "Luodaan asiakas" << endl;
    cout << endl;
    Pankkitili pa("Aapo");
    Asiakas A("Aapo", 1000);
    A.setNimi();
    cout << "Anna pankkitilin saldo: ";
    A.setSaldo();
    cout << "Anna luottoraja: ";
    A.setLuottoRaja();
    A.setVelka();
    cout << endl;
    A.showSaldo();

    cout << endl;

    cout << "Luodaan toinen asiakas" << endl;
    Asiakas B("Kirsi", 1000);
    B.setNimi();
    cout << "Anna pankkitilin saldo: ";
    B.setSaldo();
    cout << "Anna luottoraja: ";
    B.setLuottoRaja();
    cout << endl;
    B.showSaldo();

    cout << endl;

    int valinta;
    double summa;
    bool running = true;

    while (running) {
        bool accountMenu = true;
        cout << "Valitse käyttäjä:" << endl;
        cout << endl;
        cout << "1. Käyttäjä " << A.getNimi() << endl;
        cout << "2. Käyttäjä " << B.getNimi() << endl;
        cout << "3. Poistu" << endl;
        cout << endl;
        cin >> valinta;

        switch(valinta) {
            case 1: {
                while (accountMenu) {
                    int valinta2;
                    cout << "Valitse seuraavista vaihtoehdoista:" << endl;
                    cout << endl;
                    cout << "1. Katso tiedot" << endl;
                    cout << "2. Nosto" << endl;
                    cout << "3. Talletus" << endl;
                    cout << "4. Luoton nosto" << endl;
                    cout << "5. Luoton maksu" << endl;
                    cout << "6. Tilisiirto" << endl;
                    cout << "7. Vaihda käyttäjää" << endl;
                    cout << endl;
                    cin >> valinta2;

                    switch(valinta2) {
                        case 1: {
                            A.showSaldo();
                            cout << endl;
                            break;
                        }
                        case 2: {
                            cout << "Anna nostosumma: " << endl;
                            cin >> summa;
                            A.nosto(summa);
                            break;
                        }
                        case 3: {
                            cout << "Anna talletussumma: " << endl;
                            cin >> summa;
                            A.talletus(summa);
                            break;
                        }
                        case 4: {
                            cout << "Anna nostosumma: " << endl;
                            cin >> summa;
                            A.luotonNosto(summa);
                            break;
                        }
                        case 5: {
                            cout << "Anna talletussumma: " << endl;
                            cin >> summa;
                            A.luotonMaksu(summa);
                            break;
                        }
                        case 6: {
                            cout << "Anna siirtosumma: " << endl;
                            cin >> summa;
                            A.tiliSiirto(summa, B);
                            break;
                        }
                        case 7: {
                            accountMenu = false;
                            break;
                        }
                        default: {
                            cout << "Väärä valinta, kokeile uudestaan" << endl;
                        }
                    }
                }
                break;
            }
            case 2: {
                while(accountMenu) {
                    int valinta2;
                    cout << "Valitse seuraavista vaihtoehdoista:" << endl;
                    cout << endl;
                    cout << "1. Katso tiedot" << endl;
                    cout << "2. Nosto" << endl;
                    cout << "3. Talletus" << endl;
                    cout << "4. Luoton nosto" << endl;
                    cout << "5. Luoton maksu" << endl;
                    cout << "6. Tilisiirto" << endl;
                    cout << "7. Vaihda käyttäjää" << endl;
                    cout << endl;
                    cin >> valinta2;

                    switch(valinta2) {
                        case 1: {
                            B.showSaldo();
                            cout << endl;
                            break;
                        }
                        case 2: {
                            cout << "Anna nostosumma: " << endl;
                            cin >> summa;
                            B.nosto(summa);
                            break;
                        }
                        case 3: {
                            cout << "Anna talletussumma: " << endl;
                            cin >> summa;
                            B.talletus(summa);
                            break;
                        }
                        case 4: {
                            cout << "Anna nostosumma: " << endl;
                            cin >> summa;
                            B.luotonNosto(summa);
                            break;
                        }
                        case 5: {
                            cout << "Anna talletussumma: " << endl;
                            cin >> summa;
                            B.luotonMaksu(summa);
                            break;
                        }
                        case 6: {
                            cout << "Anna siirtosumma: " << endl;
                            cin >> summa;
                            B.tiliSiirto(summa, A);
                            break;
                        }
                        case 7: {
                            accountMenu = false;
                            break;
                        }
                        default: {
                            cout << "Väärä valinta, kokeile uudestaan" << endl;
                        }
                    }
                }
                break;
            }
            case 3: {
                running = false;
                break;
            }
            default:
                cout << "Väärä valinta, kokeile uudestaan" << endl;
        }

    }
    return 0;
}
