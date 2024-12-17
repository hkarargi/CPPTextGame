#include <iostream> 
#include <stdlib.h> 
#include <vector>
#include <string>
#include <windows.h>
#include "logic.h"
#include "enemies.h"
#include "graphics.h"

using namespace std;

// Score Init
int logic::score = 0;

// Shooting Vars Init
int logic::charge = 0;
Enemy* logic::nearestEnemy = 0;

// Player Position Init
int logic::playerX = 4;

// Movement Init
bool logic::moved = false;
std::string logic::doMove = "NONE";
std::string logic::moves[5] = {"RIGHT","LEFT","UP","DOWN","Z"};

// Tickrate Init

const double logic::tickRate = 0.5;

// Game Vars Init

clock_t logic::begin_time = clock();
const int logic::turns = 2;
int logic::turn = 0;
const int logic::chargeSpeed = 2;

// Game
void logic::runGame()
{
	begin_time = clock();
	if (turns <= 1 && moved)
	{
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
	}
	if (chargeSpeed <= 1 && moved)
		logic::addCharge(1);
	if (logic::getMove() == "RIGHT" && logic::getPlayerX() < 8)
	{
		logic::setPlayerX(logic::getPlayerX() + 1);
		Enemy::enemiesClear();
		graphics::printScreen();
		turn += 1;
	}
	else if (logic::getMove() == "LEFT" && logic::getPlayerX() > 0)
	{
		logic::setPlayerX(logic::getPlayerX() - 1);
		Enemy::enemiesClear();
		graphics::printScreen();
		turn += 1;
	}
	else if (logic::getMove() == "UP")
	{
		logic::shootNearestEnemy();
		Enemy::enemiesClear();
		graphics::printScreen();
		turn += 1;
	}
	else if (logic::getMove() == "DOWN")
	{
		Enemy::enemiesClear();
		graphics::printScreen();
		turn += 1;
	}
	else if (logic::getMove() == "Z" && charge >= 2 && charge)
	{
		logic::shootNearestEnemy(logic::getCharge() - (charge % 2));
		logic::setCharge(logic::getCharge() % 2);
		Enemy::enemiesClear();
		graphics::printScreen();
		turn += 1;
	}
	if (turns > 1 && turn % turns == 1 && moved)
	{
		logic::pushEnemiesRow();
		logic::createEnemyRow();
		Enemy::enemiesClear();
		graphics::printScreen();
	}
	if (chargeSpeed > 1 && turn % chargeSpeed == 1 && moved)
		logic::addCharge(1);
	logic::setMove("NONE");
}

clock_t logic::getBegin_time()
{
	return begin_time;
}

// Array Logic
template<typename array, typename item>
inline bool logic::contains(array&& a, item t)
{
	return std::find(begin(a), end(a), t) != end(a);
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
		int type = 0;
		if (logic::getScore() >= 50 && logic::getScore() < 100)
			type = rand() % 3 + 1;
		else if (logic::getScore() >= 100 && logic::getScore() < 250)
			type = min(rand() % 4 + 1, rand() % 4 + 1);
		else if (logic::getScore() >= 250 && logic::getScore() < 500)
			type = rand() % 4 + 1;
		else if (logic::getScore() >= 500)
			type = max(rand() % 4 + 1, rand() % 4 + 1);
		else
			type = rand() % 2 + 1;
		int newX = rand() % 9;
		int newY = 0;
		if (Enemy::positionTaken(newX, newY))
			for (int i = 3;i>=0;i--)
				int newX = rand() % 8;
		if (!Enemy::positionTaken(newX, newY) && type == 1)
			Enemy::enemies.push_back(new Circle(newX, newY));
		else if (!Enemy::positionTaken(newX, newY) && type == 2)
			Enemy::enemies.push_back(new Asterisk(newX, newY));
		else if (!Enemy::positionTaken(newX, newY) && type == 3 && logic::getScore())
			Enemy::enemies.push_back(new Cross(newX, newY));
		else if (!Enemy::positionTaken(newX, newY) && type == 4 && logic::getScore())
			Enemy::enemies.push_back(new Tilde(newX, newY));
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
	if (getNearestEnemy()->getHealth() - 1 <= 0)
		getNearestEnemy()->setIfShotToDeath(true);
	getNearestEnemy()->setHealth(getNearestEnemy()->getHealth() - 1);
}

void logic::shootNearestEnemy(int damage)
{
	logic::findNearestEnemy();
	if (getNearestEnemy()->getHealth() - damage <= 0)
		getNearestEnemy()->setIfShotToDeath(true);
	getNearestEnemy()->setHealth(getNearestEnemy()->getHealth() - damage);
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
	else if (GetKeyState('Z') & 0x8000 && !moved)
		setMove("Z");
}

bool logic::getMoved()
{
	return moved;
}

string logic::getMove()
{
	return doMove;
}

void logic::setMove(string moveString)
{
	if (contains(moves,moveString))
	{
		doMove = moveString;
		moved = true;
	}
	else
	{
		doMove = "NONE";
		moved = false;
	}
}

int logic::getScore()
{
	return score;
}

void logic::setScore(int newScore)
{
	score = newScore;
}

void logic::addScore(int addScore)
{
	score += addScore;
}

// Charge Shoot

int logic::getCharge()
{
	return charge;
}

void logic::setCharge(int newCharge)
{
	if (newCharge < 8 && newCharge >= 0)
		charge = newCharge;
}

void logic::addCharge(int addCharge)
{
	if ((charge + addCharge) <= 8 && (charge + addCharge) >= 0)
		charge += addCharge;
	else if ((charge + addCharge) >= 8)
		charge = 8;
	else if ((charge + addCharge) <= 0)
		charge = 0;
}

// Tickrate 

double logic::getTickrate()
{
	return tickRate;
}
