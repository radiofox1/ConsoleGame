#ifndef IMMOVABLE_H
#define IMMOVABLE_H


#include <iostream>

using namespace std;

class Immovable {
private:
    int posX;
    int posY;
    string mName;

public:

    Immovable(string name)
        : posX(0),
        posY(0),
        mName(name)
         {}

    void draw() {
        cout << mName << " is at " << getX() << ":" << getY() << endl;
    }

    void setPos(int x, int y) {
        posX = x;
        posY = y;
    }


    int getX() { return posX; }
    int getY() { return posY; }
    string getName() { return mName; }
};

#endif // IMMOVABLE_H
