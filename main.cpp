#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Logic/Objects/gameobject.h"
#include "Logic/Objects/monster.h"
#include "Logic/Objects/player.h"
#include "Logic/Objects/immovable.h"
#include "Logic/Objects/water.h"
#include "Logic/Objects/castle.h"
#include "Logic/Objects/tree.h"
#include "Logic/gameboard.h"

#include "game.h"

using namespace std;


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int sumHp = 0;
    string plName;
    Game mGame;
    mGame.initializeGame(plName);

    Water mWater ("water");
    mWater.setPos(1, 5);
    Castle mCastle ("castle");
    mCastle.setPos(2, 3);

    Tree mTree ("tree");
    mTree.setPos(1, 3);

 //   Player mPlayer("Geralt from Rivia");
    Player mPlayer(plName);
    Monster mMonster("Drowner");

    mMonster.setPos(1, 1);

    mMonster.setFight(55, 2);
    mPlayer.setFight(60, 5);

//    void limits (int lx, int ly);

    char userInput = 0;
    cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
    while (userInput != 'x') {
//        cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
        cin >> userInput;
        if (userInput == 'w') {
            mPlayer.move(0, -1);
        }
        else if (userInput == 's') {
            mPlayer.move(0, 1);
        }
        else if (userInput == 'a') {
            mPlayer.move(-1, 0);
        }
        else if (userInput == 'd') {
            mPlayer.move(1, 0);
        }


        if (mPlayer.getX() == mWater.getX()
                && mPlayer.getY() == mWater.getY()) {
            cout << "You met the water at the coordinates: " << mWater.getX() << "," << mWater.getY() << " and walked away from the water. Try to get around!" << endl;
            mPlayer.getX()--;
            mPlayer.getY()--;
        }

        if (mPlayer.getX() == mTree.getX()
                && mPlayer.getY() == mTree.getY()) {
            cout << "You met the tree at the coordinates: " << mTree.getX() << "," << mTree.getY() << " and walked away from the tree. Try to get around!" << endl;
            mPlayer.getX()--;
            mPlayer.getY()--;
        }


        if (mPlayer.getX() == mCastle.getX()
                && mPlayer.getY() == mCastle.getY()) {
            cout << "You met the castle at the coordinates: " << mCastle.getX() << "," << mCastle.getY() << " and your HP increased +10" << endl;
            cout << "Your HP = " << mPlayer.getHp() + 10 << endl;
        }

        if (mPlayer.getX() == mMonster.getX()
            && mPlayer.getY() == mMonster.getY()) {

            cout << mPlayer.getName() << " will fight " << mMonster.getName() << endl;
            cout << "PlayerHp = " << mPlayer.getHp() << " " << "MonsterHp = " << mMonster.getHp() << endl;
            cout << "MonsterDamage = " << mMonster.getDamage() << endl;


            if ( (mPlayer.getHp() > mMonster.getHp()) || (mPlayer.getHp() < mMonster.getHp())) {
                while (mMonster.getHp() > 0) {
                //for(int i = 0; i <= mMonster.getHp(); i++) {

                    mPlayer.getHp() = mPlayer.getHp() - mMonster.getDamage();
                    cout << "PlayerHp = " << mPlayer.getHp() << " " << "PlayerDamage = " << mPlayer.getDamage() << endl;

                    mMonster.getHp() = mMonster.getHp() - mPlayer.getDamage();
                    cout << "MonsterHp = " << mMonster.getHp() << " " << "MonsterDamage = " << mMonster.getDamage() << endl;

                    sumHp = sumHp + mPlayer.getDamage(); //total damage


                        if(mPlayer.getHp() > 0) {
                            if(mMonster.getHp() <= 0){
                            cout << "You win the monster!" << endl;
                            cout << "Total player damage: " << sumHp << endl;
                            mMonster.setPos(rand() % GameBoard::BOARD_HEIGHT, rand() % GameBoard::BOARD_WIDTH);
                            //mMonster = mGround;
                            }
                        }
                        else{
                           mGame.endGame();
                           //cout << "GameOver!" << endl;
                        }
                }
            }

            //lvl up
            if (sumHp >= 50){
                mPlayer.setFight(70, 7);
                cout << "You moved to the second level! Your health has been updated to 70, damage increased to 7" << endl;
            }
            if (sumHp >= 100){
                mPlayer.setFight(90, 9);
                cout << "You moved to the second level! Your health has been updated to 90, damage increased to 9" << endl;
            }
        }


            mPlayer.draw();
        }

    return 0;
}
