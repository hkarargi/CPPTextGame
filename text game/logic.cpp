#include "logic.h"
#include "enemies.h"
#include <iostream>
using namespace std;

// Logic Vars Init
int logic::playerX = 4;
Enemy* logic::nearestEnemy;

// Tickrate Init
const double logic::tickRate = 2;

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
		if (Enemy::positionTaken(newX, newY))
			break;
		if (type == 1)
		{
			Enemy::enemies.push_back(new Circle(newX,newY));
		}
		else if (type == 2)
		{
			Enemy::enemies.push_back(new Asterisk(newX, newY));
		}
	}
	logic::findNearestEnemy();
}

void logic::pushEnemiesRow()
{
	for (int i = 0; i < Enemy::enemies.size(); i++)
		Enemy::enemies[i]->setY(Enemy::enemies[i]->getY() + 1);
	nearestEnemy->setX(nearestEnemy->getX()+1);
}

void logic::findNearestEnemy()
{
	Enemy* enemyShot = new Enemy();
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (Enemy::enemies[i]->getType() != 0)
		{
			if (playerX == Enemy::enemies[i]->getX())
			{
				if (7 - Enemy::enemies[i]->getY() < 7 - enemyShot->getY())
				{
					enemyShot = Enemy::enemies[i];
				}
			}
		}
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