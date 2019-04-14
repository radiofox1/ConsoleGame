#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "Logic/gameboard.h"

using namespace std;

class GameObject {
private:
    int posX;
    int posY;
    string mName;
    int fightHp;
    int fightDamage;


public:
    GameObject() {}

    GameObject(string name)
        : posX(0),
        posY(0),
        mName(name),
        fightHp(0),
        fightDamage(0)
         {}


    void draw() {
        cout << mName << " is at " << getX() << ":" << getY() << endl;
    }

    void setPos(int x, int y) {
        posX = x;
        posY = y;
    }

    void setFight(int hp, int damage) {
        fightHp = hp;
        fightDamage = damage;
    }

    int& getX() { return posX; }
    int& getY() { return posY; }
    int& getHp() { return fightHp; }
    int& getDamage() { return fightDamage; }
    string getName() { return mName; }
};

#endif // GAMEOBJECT_H
