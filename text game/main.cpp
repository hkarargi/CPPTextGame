#include <iostream> 
#include <stdlib.h> 
#include <vector>
#include <windows.h>
#include "enemies.h"
#include "graphics.h"
#include "logic.h"
#include "old_graphics.h"

using namespace std;

clock_t begin_time = clock();

static void runGame()
{
	if (logic::getMove() == "LEFT" && logic::getPlayerX() > 0)
	{
		logic::setPlayerX(logic::getPlayerX() - 1);
		Enemy::enemiesClear();
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
		graphics::printScreen();
	}
	if (logic::getMove() == "RIGHT" && logic::getPlayerX() < 8)
	{
		logic::setPlayerX(logic::getPlayerX() + 1);
		Enemy::enemiesClear();
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
		graphics::printScreen();
	}
	if (logic::getMove() == "UP")
	{
		Enemy::enemiesClear();
		logic::shootNearestEnemy();
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
		graphics::printScreen();
	}
	if (logic::getMove() == "DOWN")
	{
		Enemy::enemiesClear();
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
		graphics::printScreen();
	}
	if (logic::getMove() != "NONE")
	{
		Enemy::enemiesClear();
	}
	logic::setMove("");
}

int main()
{
	cout << "Game Settings: \n";

	cout << "*Default tickrate is 1*\nWhat tickrate do you want? (in seconds): ";
	
	logic::setTickrate();

	graphics::printScreen();
	
	while (true)
	{
		logic::getKeys();
		if (logic::getTickrate() <= double(clock() - begin_time) / 1000)
		{
			begin_time = clock();
			runGame();
		}
		if (logic::getTickrate() * 4 <= double(clock() - graphics::getPrint_time()) / 1000)
		{
			graphics::printScreen();
		}
	}
	return 0;
}