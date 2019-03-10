#include <QCoreApplication>
#include <iostream>

using namespace std;

class Player{
   public:

    int posX = 0;
    int posY = 0;
    int hp = 0;
    int damage = 0;

};

class Monster{
public:

    int posX = 1;
    int posY = 0;
    int hp = 0;
    int damage = 0;
};

class GameBoard{
public:

    const int maxX = 5;
    const int maxY = 5;
    const int hp = 7;
    const int damage = hp;
};


class Immovable{

class Earth{
public:

    int posX = 0;
    int posY = 0;

};

class Water{
public:

    int posX = 0;
    int posY = 0;

};

class Tree{
public:

    int posX = 0;
    int posY = 0;

};
};

class Game{
public:
    Player player;
    Monster monster;
    GameBoard gameboard;


void draw(){

    cout<<"The player located "<<player.posX<<" "<<player.posY<<"\n";

}

void moveForward() {

    if(player.posY < gameboard.maxY){
        player.posY++;
        draw();
    }
    else{
        cout<<"You have reached the top of the field. Choose a letter: " << endl << "S to go back"
           << endl << "A to go left" << endl << "D to go right" << endl;

    }
}
void moveBackward() {

    if(player.posY > 0){
        player.posY--;
        draw();
    }
    else{
        cout<<"You have reached the bottom of the field. Choose a letter: " << endl << "W to go forward"
           << endl << "A to go left" << endl << "S to go right" << endl;
    }
}
void moveRight() {

    if(player.posX < gameboard.maxX){
        player.posX++;
        draw();
    }
    else{
        cout<<"You have reached the right of the field. Choose a letter: " << endl << "W to go forward"
           << endl << "S to go back" << endl << "A to go left" << endl;
    }
}
void moveLeft() {

    if(player.posX > 0){
        player.posX--;
        draw();
    }
    else{
        cout<<"You have reached the left of the field. Choose a letter: " << endl << "W to go forward"
           << endl << "S to go back" << endl << "D to go right" << endl;
    }

}

void battle() {

//    if(player.posX && player.posY == monster.posX && monster.posY){
    if(player.posX == monster.posX){
        cout << "You met a monster";
        if (player.hp != 0){
            monster.damage++;
            cout << "monster damage: "<< monster.damage << endl;
            player.hp--;
            cout << "player hp: " << player.hp;
        } else {
    cout << "Game over";
    }
        if (monster.hp != 0){
            player.damage++;
            cout << "player damage: "<< player.damage << endl;
            monster.hp--;
            cout << "monster hp: " << monster.hp;
        } else {
    cout << "You beat the monster";
        }

//      draw();
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Game game;

    char userInput='o';

    game.draw();
    game.battle();

while (1) {
cin >> userInput;
     if (userInput == 'w') {
     game.moveForward();
     } else if (userInput == 'a') {
     game.moveLeft();
     } else if (userInput == 'd') {
     game.moveRight();
     } else if (userInput == 's') {
     game.moveBackward();
     }
}

    return a.exec();
}
