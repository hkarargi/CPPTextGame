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
	static clock_t getPrint_time();
	static clock_t getEnd_print_time();
private:
	
	// Graphics Vars
	static Enemy* map[9][10];
	static clock_t print_time;
	static clock_t end_print_time;
};

#endif
