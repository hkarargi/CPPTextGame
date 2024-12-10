#ifndef LOGIC_H
#define LOGIC_H

#include <ctime>
#include "enemies.h"

class logic 
{
public:

	// Tickrate
	static const double tickRate;
	
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
private:

	// Logic Vars
	static int playerX;
	static Enemy* nearestEnemy;
};

#endif