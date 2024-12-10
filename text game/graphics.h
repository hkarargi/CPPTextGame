#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<iostream>
#include<iomanip>
#include "enemies.h"

using namespace std;

class graphics {
public:
	
	// Print Screen
	static void printScreen();
private:

	// Graphics Vars
	static Enemy* map[9][10];
};

#endif
