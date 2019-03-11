// SimpleGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Player {
public:

	int posX = 0;
	int posY = 0;
	int hp = 0;
	int damage = 0;

};

class Monster {
public:

	int posX = 1;
	int posY = 0;
	int hp = 0;
	int damage = 0;
};

class GameBoard {
public:

	const int maxX = 5;
	const int maxY = 5;
	const int hp = 7;
	const int damage = hp;
};

//inheritance

class Immovable {
public:
	int posX = 0;
	int posY = 0;

	void Position() {
		string position = "Imovable";
		cout << "You on the  of " << position << endl;
	}
};


/*		class Ground : public Immovable {
			//public:
			Ground() {
//				position = "ground";
			}
		}; */


		class Ground {
		public:

			int posX = 0;
			int posY = 0;

		};

		class Water {
		public:

			int posX = 0;
			int posY = 0;

		};

		class Tree {
		public:

			int posX = 0;
			int posY = 0;

		};

class Game {
public:
	Player player;
	Monster monster;
	GameBoard gameboard;
	Water water;


	void draw() {

		cout << "The player located " << player.posX << " " << player.posY << "\n";

	}
//move player

	void moveForward() {

		if (player.posY < gameboard.maxY) {
			player.posY++;
			draw();
		}
		else {
			cout << "You have reached the top of the field. Choose a letter: " << endl << "S to go back"
				<< endl << "A to go left" << endl << "D to go right" << endl;

		}
	}
	void moveBackward() {

		if (player.posY > 0) {
			player.posY--;
			draw();
		}
		else {
			cout << "You have reached the bottom of the field. Choose a letter: " << endl << "W to go forward"
				<< endl << "A to go left" << endl << "S to go right" << endl;
		}
	}
	void moveRight() {

		if (player.posX < gameboard.maxX) {
			player.posX++;
			draw();
		}
		else {
			cout << "You have reached the right of the field. Choose a letter: " << endl << "W to go forward"
				<< endl << "S to go back" << endl << "A to go left" << endl;
		}
	}
	void moveLeft() {

		if (player.posX > 0) {
			player.posX--;
			draw();
		}
		else {
			cout << "You have reached the left of the field. Choose a letter: " << endl << "W to go forward"
				<< endl << "S to go back" << endl << "D to go right" << endl;
		}

	}
//battle player with monster

	void battle() {

		//    if(player.posX && player.posY == monster.posX && monster.posY){
		if (player.posX == monster.posX && player.posY == monster.posY){
		//if (player.posX == monster.posX) {
			cout << "You met a monster";
			if (player.hp != 0) {
				monster.damage++;
				cout << "monster damage: " << monster.damage << endl;
				player.hp--;
				cout << "player hp: " << player.hp;
			}
			else {
				cout << "Game over";
			}
			if (monster.hp != 0) {
				player.damage++;
				cout << "player damage: " << player.damage << endl;
				monster.hp--;
				cout << "monster hp: " << monster.hp;
			}
			else {
				cout << "You beat the monster";
			}

			//      draw();
		}
	}
//step on the water

	void stepByWater() {
		if (player.posX == water.posX && player.posY == water.posY) {
			cout << "You stepped on water";
			player.posX++;
			draw();
		}
	}
};



int main()

	{
		Game game;

		char userInput = 'o';

		game.draw();
		game.battle();
		game.stepByWater();

		while (1) {
			cin >> userInput;
			if (userInput == 'w') {
				game.moveForward();
			}
			else if (userInput == 'a') {
				game.moveLeft();
			}
			else if (userInput == 'd') {
				game.moveRight();
			}
			else if (userInput == 's') {
				game.moveBackward();
			}
		}


    return 0;
}

