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

	// Screen Size
	static const int width;
	static const int height;
private:
	
	// Graphics Vars
	static clock_t print_time;
	static clock_t end_print_time;
};

#endif
