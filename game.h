#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

using namespace std;

class Game
{
public:

    void initializeGame(string &plName)
    {
        cout << "Enter your name: ";
        cin >> plName;
    }

    void endGame()
    {
        cout << "Game Over!!!" << endl;
    }

    void reloadGame()
    {
        cout << "Reload Game? (Y/N)" << endl;
    }


};

#endif // GAME_H
