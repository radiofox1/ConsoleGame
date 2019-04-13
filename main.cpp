#include <iostream>

#include "Logic/Objects/gameobject.h"
#include "Logic/Objects/monster.h"
#include "Logic/Objects/player.h"
#include "Logic/gameboard.h"
#include "Logic/battle.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    int sumHp = 0;
    string plName;
    Game mGame;
    mGame.initializePlayer(plName);


 //   Player mPlayer("Geralt from Rivia");
    Player mPlayer(plName);
    Monster mMonster("Drowner");

    mMonster.setPos(1, 1);
//    mMonster.setPos(1, 2);
    mMonster.setFight(55, 2);
    mPlayer.setFight(60, 5);

    void limits (int lx, int ly);

    char userInput = 0;
    cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
    while (userInput != 'x') {
//        cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
        cin >> userInput;
        if (userInput == 'w') {
            mPlayer.move(0, 1);
        }
        else if (userInput == 's') {
            mPlayer.move(0, -1);
        }
        else if (userInput == 'a') {
            mPlayer.move(-1, 0);
        }
        else if (userInput == 'd') {
            mPlayer.move(1, 0);
        }


        if (mPlayer.getX() == mMonster.getX()
            && mPlayer.getY() == mMonster.getY()) {

            cout << mPlayer.getName() << " will fight " << mMonster.getName() << endl;
            cout << "PlayerHp = " << mPlayer.getHp() << " " << "MonsterHp = " << mMonster.getHp() << endl;
            cout << "MonsterDamage = " << mMonster.getDamage() << endl;


            if ( mPlayer.getHp() > mMonster.getHp() ) {
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
                            mMonster.setPos(1000000, 1000000);
                            //mMonster = mGround;
                            }
                        }
                        else{
                           mGame.endGame();
                           //cout << "GameOver!" << endl;
                        }
                }
            }
            else {
                while (mPlayer.getHp() > 0) {
            //    for(int i = 0; i <= mPlayer.getHp(); i++) {
                    mPlayer.getHp() = mPlayer.getHp() - mMonster.getDamage();
                    cout << "PlayerHp = " << mPlayer.getHp() << " " << "PlayerDamage = " << mPlayer.getDamage() << endl;

                    mMonster.getHp() = mMonster.getHp() - mPlayer.getDamage();
                    cout << "MonsterHp = " << mMonster.getHp() << " " << "MonsterDamage = " << mMonster.getDamage() << endl;
                    sumHp = sumHp + mPlayer.getDamage(); //total damage

                        if(mPlayer.getHp() > 0) {
                            if(mMonster.getHp() <= 0){
                            cout << "You win the monster!" << endl;
                            mMonster.setPos(1000000, 1000000);
                            }
                        }
                        else{

                           mGame.endGame();
                          // cout << "GameOver!" << endl;
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
