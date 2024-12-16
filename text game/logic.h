#ifndef LOGIC_H
#define LOGIC_H

#include <ctime>
#include <string>
#include "enemies.h"

class logic 
{
public:
	
	// Basic Logic
	template<typename array, typename item>
	static bool contains(array&& a, item t);

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

	// Getting Keys
	static void getKeys();
	static std::string getMove();
	static void setMove(std::string moveString);

	// Tickrate Related
	static double getTickrate();
	static void setTickrate();
	static void setTickrate(int rate);
private:

	// Logic Vars
	static int playerX;
	static Enemy* nearestEnemy;
	static bool moved;
	static int doMove;

	// Tickrate
	static double tickRate;
};

#endif