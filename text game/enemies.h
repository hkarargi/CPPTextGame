#ifndef ENEMIES_H
#define ENEMIES_H
#define posX pos.first
#define posY pos.second

#include<vector>

class Enemy 
{
public:
	// Enemy Constructor/Deconstructor
	Enemy();
	Enemy(int tp, int enemyX, int enemyY);
	~Enemy();

	// Enemies Vector
	static std::vector<Enemy*> enemies;
	static void enemiesClear();

	// Enemy Type
	int getType() const;
	void setType(int type);

	// Enemy Health
	double getHealth() const;
	void setHealth(double hp);

	// Enemy Position
	std::pair<int, int> getPosPair() const;
	int getX() const;
	int getY() const;
	void setX(int enemyX);
	void setY(int enemyY);

	// Printing Related
	int getBufferPos() const;
	static Enemy* getEnemyByBufferPos(int bufferPos);

	// Enemy Search
	static Enemy* getEnemyByPos(int x, int y);
	static bool positionTaken(int x, int y);

private:

	// Enemy Vars
	int typeID;
	double health;
	std::pair<int, int> pos;
};

class Circle : public Enemy
{
public:
	Circle();
	Circle(int enemyX, int enemyY);
};

class Asterisk : public Enemy
{
public:
	Asterisk();
	Asterisk(int enemyX, int enemyY);
};

#endif
