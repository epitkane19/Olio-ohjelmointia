#include <iostream>
#include <cstdlib>

using namespace std;

int game(int maxnum);

int main() {
    int guesses;
    int maxnum;
    cout << "Anna maksimiluku: ";
    cin >> maxnum;
    cout << "Arvottu numero on 1-" << maxnum << " väliltä" << endl;
    guesses = game(maxnum);
    cout << "Arvausten lukumäärä: " << guesses << endl;
}

int game(int maxnum) {

    int x = time(0);
    srand(x);
    int rand_num = rand() % maxnum + 1;
    int guessed_num = 0;
    int guesses = 0;
    bool isRunning = true;

    while(isRunning) {
        cout << "Anna arvaus: ";
        cin >> guessed_num;
        if(guessed_num != rand_num) {
            guesses++;
            if(guessed_num < rand_num) {
                cout << "Vastaus on suurempi" << endl;
            }
            else if(guessed_num > rand_num){
                cout << "Vastaus on pienempi" << endl;
            }
        }
        else {
            guesses++;
            cout << "Arvaus on oikein" << endl;
            isRunning = false;
        }
    }
    return guesses;
}
