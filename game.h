#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

using namespace std;

class Game
{
public:

    void initializePlayer(string &name)
    {
        cout << "Enter your name: ";
        cin >> name;
    }

    void initializeMonster(string &name)
    {
        cout << "Enter monster name: ";
        cin >> name;
    }


    void endGame()
    {
        cout << "GAME OVER!!!" << endl;
        system("pause");
    }

};

#endif // GAME_H
