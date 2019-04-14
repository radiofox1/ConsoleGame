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

 /*   void initializeGameBoard(int width, int height)
    {
        int boardNum = 0;
        do
        {
            cout << "Enter the number of columns: ";

            boardNum = int(width);
        } while (!boardNum);
        boardNum = 0;
        do
        {
            cout << "Enter the number of rows: ";
            boardNum = int(height);
        } while (!boardNum);

    }*/

};

#endif // GAME_H
