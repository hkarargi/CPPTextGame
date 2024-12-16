#include "logic.h"
#include "enemies.h"
#include <stdlib.h> 
#include <iostream>
#include <windows.h>

using namespace std;

// Logic Vars Init

int logic::playerX = 4;
Enemy* logic::nearestEnemy;
bool logic::moved = false;
int logic::doMove = 0;

// Tickrate Init

double logic::tickRate = 1;

// Array Logic
template<typename array, typename item>
inline bool logic::contains(array&& a, item t)
{
	return false;
}

// Player Position

int logic::getPlayerX()
{
	return playerX;
}

void logic::setPlayerX(int x)
{
	playerX = x;
}

// Enemy Creation and Movement

void logic::createEnemyRow()
{
	for (int i = rand() % 8 + 1; i >= 0; i--)
	{
		int type = rand() % 2 + 1;
		int newX = rand() % 8;
		int newY = 0;
		if (Enemy::positionTaken(newX, newY))
		{
			for (int i = 3;i>=0;i--)
				int newX = rand() % 8;
		}
		if (Enemy::positionTaken(newX, newY) == false)
		{
			if (type == 1)
				Enemy::enemies.push_back(new Circle(newX, newY));
			else if (type == 2)
				Enemy::enemies.push_back(new Asterisk(newX, newY));
		}
	}
	logic::findNearestEnemy();
}

void logic::pushEnemiesRow()
{
	for (int i = 0; i < Enemy::enemies.size(); i++)
		Enemy::enemies[i]->setY(Enemy::enemies[i]->getY() + 1);
}

// Finding Nearest Enemy

void logic::findNearestEnemy()
{
	Enemy* enemyShot = new Enemy();
	enemyShot->setY(-1);
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (Enemy::enemies[i]->getType() != 0 && playerX == Enemy::enemies[i]->getX() && 7 - Enemy::enemies[i]->getY() < 7 - enemyShot->getY())
			enemyShot = Enemy::enemies[i];
	}
	logic::nearestEnemy = enemyShot;
}

Enemy* logic::getNearestEnemy()
{
	logic::findNearestEnemy();
	return logic::nearestEnemy;
}

void logic::shootNearestEnemy()
{
	logic::findNearestEnemy();
	getNearestEnemy()->setHealth(getNearestEnemy()->getHealth() - 1);
}

// Getting Keys

void logic::getKeys()
{
	if (GetKeyState(VK_LEFT) & 0x8000 && !moved)
		setMove("LEFT");
	else if (GetKeyState(VK_RIGHT) & 0x8000 && !moved)
		setMove("RIGHT");
	else if (GetKeyState(VK_UP) & 0x8000 && !moved)
		setMove("UP");
	else if (GetKeyState(VK_DOWN) & 0x8000 && !moved)
		setMove("DOWN");
}

string logic::getMove()
{
	if (doMove == 1 && moved)
		return "LEFT";
	else if (doMove == 2 && moved)
		return "RIGHT";
	else if (doMove == 3 && moved)
		return "UP";
	else if (doMove == 4 && moved)
		return "DOWN";
	else
		return "NONE";
}

void logic::setMove(string moveString)
{
	if (moveString == "LEFT")
	{
		doMove = 1;
		moved = true;
	}
	else if (moveString == "RIGHT")
	{
		doMove = 2;
		moved = true;
	}
	else if (moveString == "UP")
	{
		doMove = 3;
		moved = true;
	}
	else if (moveString == "DOWN")
	{
		doMove = 4;
		moved = true;
	}
	else
	{
		doMove = 0;
		moved = false;
	}
}

// Tickrate 

double logic::getTickrate()
{
	return tickRate;
}

void logic::setTickrate()
{
	cin >> tickRate;
}

void logic::setTickrate(int rate)
{
	tickRate = rate;
}
