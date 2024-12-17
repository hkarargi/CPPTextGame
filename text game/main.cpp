#include <iostream> 
#include <stdlib.h> 
#include <vector>
#include <windows.h>
#include "enemies.h"
#include "graphics.h"
#include "logic.h"

using namespace std;

clock_t begin_time = clock();

int main()
{
	begin_time = clock();
	cout << "Controls: \n\nUp Arrow: Shoot\nDown Arrow: Skip Turn\nRight Arrow: Go Right\nLeft Arrow: Go Left\nZ: Shoot Charged Shot";
	Sleep(1000 * (logic::getTickrate() * 5 - double(clock() - begin_time) / 1000));

	graphics::printScreen();
	
	while (true)
	{
		logic::getKeys();
		if (logic::getTickrate() <= double(clock() - logic::getBegin_time()) / 1000)
		{
			logic::runGame();
		}
		if (logic::getTickrate() * 4 <= double(clock() - graphics::getPrint_time()) / 1000)
		{
			graphics::printScreen();
		}
	}
	return 0;
}