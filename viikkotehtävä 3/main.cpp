#include <chef.h>
#include <iostream>
#include <string>

using namespace std;





int main()
{
    ItalianChef ita("Giovanni (default)");
    ita.getName();
    int number;
    bool running = true;
    do {
        running = false;
        cout << "Valitse seuraavista vaihtoehdoista:" << endl;
        cout << "[1] Salad" << endl;
        cout << "[2] Soup" << endl;
        cout << "[3] VIP" << endl;
        cin >> number;
        int ainekset;
        string salasana;
        switch (number) {
        case 1:
            cout << "Anna ainesten määrä: ";
            cin >> ainekset;
            ita.makeSalad(ainekset);
            break;
        case 2:
            cout << "Anna ainesten määrä: ";
            cin >> ainekset;
            ita.makeSoup(ainekset);
            break;
        case 3:
            ita.askSecret(salasana);
            break;
        default:
            cout << "Invalid option!" << endl;
            running = true;
        }
    } while (!cin.eof() && running);

    return 0;
}
