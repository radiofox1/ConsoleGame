#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

using namespace std;

class Game
{
public:

    void initializePlayer(string &plName)
    {
        cout << "Enter your name: ";
        cin >> plName;
    }


    void endGame()
    {
        cout << "GAME OVER!!!" << endl;
        system("pause");
    }

};

#endif // GAME_H
