#include <iostream>

#include "Logic/Objects/gameobject.h"
#include "Logic/Objects/monster.h"
#include "Logic/Objects/player.h"
#include "Logic/gameboard.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{

   // Game game;
 //   game.initializePlayer(player_name)


    Player mPlayer("Geralt from Rivia");
    Monster mMonster("Drowner");

    mMonster.setPos(1, 1);
//    mMonster.setPos(1, 2);
    mMonster.setFight(6, 1);
    mPlayer.setFight(7, 2);

    void limits (int lx, int ly);

    char userInput = 0;
    cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
    while (userInput != 'x') {
//        cout << "Select your direction: w - go forward, a - go left, s - go backward, d - go right" << endl;
        cin >> userInput;
        if (userInput == 'w') {
            if (mPlayer.getY() + 1 < GameBoard::BOARD_HEIGHT) {

            }
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
/*            while (mPlayer.getHp() > 0) {
                mPlayer.getHp() - mMonster.getDamage();
                cout << mMonster.getName() <<" damage: " << mMonster.getDamage() << endl;
               // mPlayer.getHp();
                cout << mPlayer.getName() << " hp: " << mPlayer.getHp() << endl;
               // mPlayer.getDamage();
                cout << mPlayer.getName() <<" damage: " << mPlayer.getDamage() << endl;
                mMonster.getHp();
              //  cout << mMonster.getName() << " hp: " << mMonster.getHp() << endl;

            if (mPlayer.getHp() == 0) {
                 cout << "Game over" << endl;
            }
            else if (mMonster.getHp() == 0) {
                cout << "You killed monster" << endl;
            }
} */

            if ( mPlayer.getHp() > mMonster.getHp() ) {
                for(int i = 0; i <= mMonster.getHp(); i++) {
                    cout << "PlayerHp = " << mPlayer.getHp() << " " << "MonsterDamage = " << mMonster.getDamage() << endl;
                    mPlayer.getHp() = mPlayer.getHp() - mMonster.getDamage();
                    cout << "MonsterHp = " << mMonster.getHp() << " " << "PlayerDamage = " << mPlayer.getDamage() << endl;
                    mMonster.getHp() = mMonster.getHp() - mPlayer.getDamage();

                        if(mPlayer.getHp() > 0) {
                            if(mMonster.getHp() == 0){
                            cout << "You win the monster!" << endl;
                            }
                        }
                        else{
                           cout << "GameOver!" << endl;
                        }
            //        }
                }
            }
            else {
                for(int i = 0; i <= mPlayer.getHp(); i++) {
                    cout << "PlayerHp = " << mPlayer.getHp() << " " << "MonsterDamage = " << mMonster.getDamage() << endl;
                    mPlayer.getHp() = mPlayer.getHp() - mMonster.getDamage();
                    cout << "MonsterHp = " << mMonster.getHp() << " " << "PlayerDamage = " << mPlayer.getDamage() << endl;
                    mMonster.getHp() = mMonster.getHp() - mPlayer.getDamage();

                        if(mPlayer.getHp() > 0) {
                            if(mMonster.getHp() == 0){
                            cout << "You win the monster!" << endl;
                            }
                        }
                        else{
                           cout << "GameOver!" << endl;
                        }
                }
            }
}


            mPlayer.draw();
        }

    return 0;
}
