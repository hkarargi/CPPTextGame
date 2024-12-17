#include<iostream>
#include<iomanip>
#include<stdlib.h> 
#include<string>
#include<windows.h>
#include "graphics.h"
#include "enemies.h"
#include "logic.h"

using namespace std;

const int graphics::width = 8;
const int graphics::height = 9;
clock_t graphics::print_time = clock();
clock_t graphics::end_print_time = clock();

void graphics::printScreen()
{
	print_time = clock();
	logic::findNearestEnemy();

	const int total_cells = (width + 2) * (height + 2);
	string buffer;

	for (int i = 1; i <= total_cells; i++)
	{
		if (Enemy::getEnemyByBufferPos(i - 1)->getType() != 0 || Enemy::getEnemyByBufferPos(i - 1)->getHealth() != 0)
			buffer += "\033[0m";
		if (i % (width + 2) == 1 && i != 1)
			buffer += "\n";

		if (i == 1)
			buffer += " ";
		else if (i <= (width + 2) && i != 1)
			buffer += to_string(i - 2)[0];
		else if (i / (width + 2) <= (height + 2) && i % (width + 2) == 1 && i != 1)
			buffer += to_string((i / (width + 2)) - 1);
		else if (i == (9 * (width + 2) + (width + 2) + logic::getPlayerX() + 2))
			buffer += "^";
		else if (Enemy::getEnemyByBufferPos(i)->getHealth() <= 8 && Enemy::getEnemyByBufferPos(i)->getHealth() > 0 && Enemy::getEnemyByBufferPos(i) == logic::getNearestEnemy())
			buffer += "\033[38;5;" + to_string(int(Enemy::getEnemyByBufferPos(i)->getHealth()) + 8) + "m";
		else if (Enemy::getEnemyByBufferPos(i)->getHealth() <= 8 && Enemy::getEnemyByBufferPos(i)->getHealth() > 0 && Enemy::getEnemyByBufferPos(i) != logic::getNearestEnemy())
			buffer += "\033[38;5;" + to_string(int(Enemy::getEnemyByBufferPos(i)->getHealth())) + "m";
		else if (Enemy::getEnemyByBufferPos(i)->getHealth() > 8 && Enemy::getEnemyByBufferPos(i) == logic::getNearestEnemy())
			buffer += "\033[38;5;" + to_string(int(Enemy::getEnemyByBufferPos(i)->getHealth()) + 24) + "m";
		else if (Enemy::getEnemyByBufferPos(i)->getHealth() > 8 && Enemy::getEnemyByBufferPos(i) != logic::getNearestEnemy())
			buffer += "\033[38;5;" + to_string(int(Enemy::getEnemyByBufferPos(i)->getHealth()) + 16) + "m";
		else
			buffer += ".";

		if (Enemy::getEnemyByBufferPos(i)->getType() == 1 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
			buffer += "o";
		else if (Enemy::getEnemyByBufferPos(i)->getType() == 2 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
			buffer += "*";
		else if (Enemy::getEnemyByBufferPos(i)->getType() == 3 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
			buffer += "+";
		else if (Enemy::getEnemyByBufferPos(i)->getType() == 4 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
			buffer += "~";

		buffer += " ";
	}

	buffer += "\033[0m\n\nScore: " + to_string(logic::getScore());

	buffer += "\n\nCharge: [ ";
	for (int i = 0; i < logic::getCharge(); i++)
	{
		buffer += "-";
		if (i % 2 == 1 && i < 7)
			buffer += "|";
	}
	for (int i = 0; i < 8 - logic::getCharge(); i++)
	{
		buffer += "_";
		if ((i + logic::getCharge()) % 2 == 1 && i < (7 - logic::getCharge()))
			buffer += "|";
	}
	buffer += " ]";
	buffer += '\0';

	system("cls");
	cout << buffer;
	end_print_time = clock();
}

clock_t graphics::getPrint_time()
{
	return print_time;
}

clock_t graphics::getEnd_print_time()
{
	return end_print_time;
}