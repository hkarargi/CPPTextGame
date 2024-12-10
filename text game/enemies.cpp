#include<string>
#include<iostream>
#include<vector>
#include "enemies.h"
#include "logic.h"

using namespace std;

// Enemy Constructor/Deconsturctor

Enemy::Enemy()
{
	this->typeID = 0;
	this->health = 0.0;
	this->pos.posX = 0;
	this->pos.posY = 0;
}

Enemy::Enemy(int tp, int enemyX, int enemyY)
{
	this->typeID = tp;
	if (tp == 1)
		this->health = 1.0;
	else if (tp == 2)
		this->health = 2.0;
	else
		this->health = 0;
	this->pos.posX = enemyX;
	this->pos.posY = enemyY;
}

Enemy::~Enemy()
{
}

// Enemies Vector Init/Clear Unneeded

std::vector<Enemy*> Enemy::enemies;

void Enemy::enemiesClear()
{
	// Game Over (If any enemy touches the player then gameover.)
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (positionTaken(logic::getPlayerX(), 9))
		{
			for (int i = 0; i < Enemy::enemies.size(); i++)
			{
				delete Enemy::enemies[i];
			}
			Enemy::enemies.erase(Enemy::enemies.begin(), Enemy::enemies.end());
			logic::setPlayerX(4);
			system("cls");
			cout << "Game Over!";
		}
	}

	// Delete enemies that are past the screen.
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (Enemy::enemies[i]->getX() >= 9 || Enemy::enemies[i]->getY() >= 10 || Enemy::enemies[i]->getHealth() <= 0)
		{
			enemies[i]->setHealth(0);
			enemies[i]->setX(0);
			enemies[i]->setY(0);
			delete Enemy::enemies[i];
			Enemy::enemies.erase(std::find(Enemy::enemies.begin(), Enemy::enemies.end(), Enemy::enemies[i]));
		}
	}

	logic::findNearestEnemy();
}

// Enemy Type

int Enemy::getType() const
{
	return typeID;
}

void Enemy::setType(int type)
{
	typeID = type;
}

// Enemy Health

double Enemy::getHealth() const
{
	return health;
}


void Enemy::setHealth(double hp)
{
	health = hp;
}

// Enemy Position

std::pair<int, int> Enemy::getPosPair() const
{
	return pos;
}

int Enemy::getX() const
{
	return pos.posX;
}

int Enemy::getY() const
{
	return pos.posY;
}

void Enemy::setX(int objectX)
{
	pos.posX = objectX;
}

void Enemy::setY(int objectY)
{
	pos.posY = objectY;
}

// Enemy Search

Enemy* Enemy::getEnemyByPos(int x, int y)
{
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (Enemy::enemies[i]->getX() == x && Enemy::enemies[i]->getY() == y)
			return Enemy::enemies[i];
	}
	return new Enemy();
}

bool Enemy::positionTaken(int x, int y)
{
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (Enemy::enemies[i]->getX() == x && Enemy::enemies[i]->getY() == y)
			return true;
	}
	return false;
};

// Circle Constructor

Circle::Circle()
{
	setType(1);
	setHealth(1.0);
}

Circle::Circle(int enemyX, int enemyY)
{
	setType(1);
	setHealth(1.0);
	setX(enemyX);
	setY(enemyY);
}

// Asterisk Constructor

Asterisk::Asterisk()
{
	setType(2);
	setHealth(2.0);
}

Asterisk::Asterisk(int enemyX, int enemyY)
{
	setType(2);
	setHealth(2.0);
	setX(enemyX);
	setY(enemyY);
}