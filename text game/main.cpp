#include <iostream> 
#include <stdlib.h> 
#include <vector>
#include <windows.h>
#include "enemies.h"
#include "graphics.h"
#include "logic.h"

using namespace std;


void runGame()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (logic::getPlayerX() > 0)
			logic::setPlayerX(logic::getPlayerX() - 1);
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		graphics::printScreen();
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (logic::getPlayerX() < 8)
			logic::setPlayerX(logic::getPlayerX() + 1);
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		graphics::printScreen();
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		logic::shootNearestEnemy();
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		graphics::printScreen();
	}
}

int main()
{
	graphics::printScreen();
	while (true)
	{
		clock_t begin_time = clock();
		runGame();
		Sleep(logic::tickRate - double(begin_time - clock())*10);
	}
	return 0;
}