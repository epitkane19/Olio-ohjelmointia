#include <cstdlib>
#include <iostream>
#include <game.h>

using namespace std;

Game::Game(int maxNum)
{
    maxNumber = maxNum;
}

Game::~Game()
{

}

void Game::play() {
    int x = time(0);
    srand(x);
    randomNumber = rand() % maxNumber + 1;
    playerGuess = 0;
    numOfGuesses = 0;
    bool isRunning = true;

    cout << "Anna maksimiluku: ";
    cin >> maxNumber;
    cout << "Arvottu numero on 1-" << maxNumber << " väliltä" << endl;

    while(isRunning) {
        cout << "Anna arvaus: ";
        cin >> playerGuess;
        if(playerGuess != randomNumber) {
            numOfGuesses++;
            if(playerGuess < randomNumber) {
                cout << "Vastaus on suurempi" << endl;
            }
            else if(playerGuess > randomNumber){
                cout << "Vastaus on pienempi" << endl;
            }
        }
        else {
            numOfGuesses++;
            cout << "Arvaus on oikein" << endl;
            isRunning = false;
            printGameResult();
        }
    }
}

void Game::printGameResult() {
    cout << "Arvausten lukumäärä: " << numOfGuesses << endl;
}


