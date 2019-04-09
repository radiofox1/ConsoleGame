#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//#include "Logic/Objects/gameobject.h"
#include "consoleColor.h"

//const char BOARD_SYMBOL{'.'};

class GameBoard {
  /*  private:

        int boardWidth;
        int boardHeight;

        char** board;

    public:
        GameBoard(int boardWidth, int boardHeight)
            :boardWidth(boardWidth),
            boardHeight(boardHeight)

        {
            board = new char *[boardWidth];
            for (int i = 0; i < boardWidth; i++)
            {
                board[i] = new char[boardHeight];
            }
        }

        int getBoardWidth()
        {
            return boardWidth;
        }

        //=======================

        int getBoardHeight()
        {
            return boardHeight;
        }

        //=======================

        char **getBoard()
        {
            return board;
        }

        //=======================

        void Board()
        {
            for (int i = 0; i < boardHeight; i++)
            {
                for (int j = 0; j < boardWidth; j++)
                    board[i][j] = BOARD_SYMBOL;
            }
        } */

public:
    static const int BOARD_HEIGHT = 10;
    static const int BOARD_WIDTH = 10;

    int mBoard[BOARD_HEIGHT][BOARD_WIDTH];
    GameBoard();


/*private:
    GameObject mBoard[BOARD_HEIGHT][BOARD_WIDTH];

    GameBoard();*/


};


#endif // GAMEBOARD_H
