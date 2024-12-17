#ifndef LOGIC_H
#define LOGIC_H

#include <ctime>
#include <string>
#include "enemies.h"

using namespace std;

class logic 
{
public:

	// Basic Logic
	template<typename array, typename item>
	static bool contains(array&& a, item t);

	// Game
	static void runGame();
	static clock_t getBegin_time();

	// Player Position
	static int getPlayerX();
	static void setPlayerX(int x);

	// Enemy Creation and Movement
	static void createEnemyRow();
	static void pushEnemiesRow();

	// Finding Nearest Enemy
	static void findNearestEnemy();
	static Enemy* getNearestEnemy();

	// Shooting
	static void shootNearestEnemy();
	static void shootNearestEnemy(int damage);
	static void shootEnemyRow(int damage);

	// Getting Keys
	static void getKeys();
	static bool getMoved();
	static std::string getMove();
	static void setMove(std::string moveString);

	// Score Related
	static int getScore();
	static void setScore(int newScore);
	static void addScore(int addScore);

	// Charge Shooting
	static int getCharge();
	static void setCharge(int newCharge);
	static void addCharge(int addCharge);

	// Tickrate
	static double getTickrate();
private:

	// Score
	static int score;

	// Shooting
	static int charge;
	static Enemy* nearestEnemy;

	// Player Position
	static int playerX;

	// Movement
	static bool moved;
	static std::string doMove;
	static std::string moves[5];

	// Tickrate
	static const double tickRate;

	// Game Vars

	static clock_t begin_time;
	static const int turns;
	static int turn;
	static const int chargeSpeed;
};

#endif