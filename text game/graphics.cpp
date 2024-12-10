#include<iostream>
#include<iomanip>
#include<stdlib.h> 
#include<windows.h>
#include "graphics.h"
#include "enemies.h"
#include "logic.h"
 
using namespace std;

Enemy* graphics::map[9][10] = {};

void graphics::printScreen()
{
	logic::findNearestEnemy();
	system("cls");

	for (int y = 0; y <= 9; y++)
	{
		for (int x = 0; x <= 8; x++)
		{
			map[x][y] = new Enemy();
		}
	}

	for (int i = 0; i < Enemy::enemies.size(); i++) 
	{
			map[Enemy::enemies[i]->getX()][Enemy::enemies[i]->getY()] = Enemy::enemies[i];
	}

	cout << " "; 
	for (int i = 0; i <= 8; i++)
		cout << setw(2) << i;
	for (int y = 0; y <= 9; y++)
	{
		for (int x = 0; x <= 8; x++)
		{
			if (x == 0)
				cout << "\n" << y;
			if (y == 9 && x == logic::getPlayerX())
				cout << setw(2) << "^";
			if (map[x][y]->getHealth() == 2)
			{
				if (map[x][y] == logic::getNearestEnemy()) {
					if (map[x][y]->getType() == 1)
						cout << setw(2) << " \033[1;36mo\033[0m";
					else if (map[x][y]->getType() == 2)
						cout << setw(2) << " \033[1;36m*\033[0m";
				}
				else {
					if (map[x][y]->getType() == 1)
						cout << setw(2) << " \033[1;34mo\033[0m";
					else if (map[x][y]->getType() == 2)
						cout << setw(2) << " \033[1;34m*\033[0m";
				}
			}
			else if (map[x][y]->getHealth() == 1)
			{
				if (map[x][y] == logic::getNearestEnemy()) {
					if (map[x][y]->getType() == 1)
						cout << setw(2) << " \033[1;33mo\033[0m";
					else if (map[x][y]->getType() == 2)
						cout << setw(2) << " \033[1;33m*\033[0m";
				}
				else {
					if (map[x][y]->getType() == 1)
						cout << setw(2) << " \033[1;31mo\033[0m";
					else if (map[x][y]->getType() == 2)
						cout << setw(2) << " \033[1;31m*\033[0m";
				}
			}
			else if (y != 9 || x != logic::getPlayerX())
				cout << setw(2) << ".";
		}
	}
//	cout << "\n";
//	cout << " ";
//	for (int i = 0; i < logic::getPlayerX(); i++)
//		cout << setw(2) << "X";
//	cout << setw(2) << "^";
//	for (int i = logic::getPlayerX(); i < 8; i++)
//		cout << setw(2) << "X";
	cout << "\n ";
	for (int i = 0; i <= 8; i++)
		cout << setw(2) << i;
	Enemy::enemiesClear();
}