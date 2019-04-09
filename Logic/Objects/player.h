#ifndef PLAYER_H
#define PLAYER_H

//#include "gameobject.h"
#include "Logic/Objects/gameobject.h"

class Player : public GameObject {
private:

public:
    Player(string name)
        : GameObject(name) {
    }

    void move(int x, int y) {
        setPos(getX() + x, getY() + y);
        if(getX() < 0){
//            getX() - x;
            cout << "Stop! You have reached the left of the field. Please move away from the edge with the buttons: "
                 << endl << "W to go forward" << endl << "S to go back" << endl << "D to go right" << endl;
        }

        if(getX() > GameBoard::BOARD_HEIGHT){


            cout << "Stop! You have reached the right of the field. Please move away from the edge with the buttons: "
                 << endl <<  "W to go forward" << endl << "S to go back" << endl << "A to go left" << endl;
        }
        if(getY() < 0){


            cout << "Stop! You have reached the bottom of the field. Please move away from the edge with the buttons: "
                 << endl <<  "W to go forward" << endl <<  "A to go left" << endl << "D to go right" << endl;
    }

        if(getY() > GameBoard::BOARD_WIDTH){


            cout << "Stop! You have reached the top of the field. Please move away from the edge with the buttons: "
                 << endl <<  "S to go back" << endl <<  "A to go left" << endl << "D to go right" << endl;
    }

}
};

#endif // PLAYER_H
