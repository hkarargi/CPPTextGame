#include<iostream>
#include<iomanip>
#include<stdlib.h> 
#include<string>
#include<windows.h>
#include "graphics.h"
#include "enemies.h"
#include "logic.h"

using namespace std;

const int graphics::width = 8;
const int graphics::height = 9;
clock_t graphics::print_time = clock();
clock_t graphics::end_print_time = clock();

void graphics::printScreen()
{
    print_time = clock();
    logic::findNearestEnemy();

    const int total_cells = (width + 2) * (height + 2);
    string buffer;

    for (int i = 1; i <= total_cells; i++)
    {
        if (Enemy::getEnemyByBufferPos(i)->getType() == 0 || Enemy::getEnemyByBufferPos(i)->getHealth() == 0)
            buffer += "\033[0m";
        if (i % (width + 2) == 1 && i != 1)
            buffer += "\n";
        
        if (i == 1)
            buffer += " ";
        else if (i <= (width + 2) && i != 1)
            buffer += to_string(i - 2)[0];
        else if (i / (width + 2) <= (height + 2) && i % (width + 2) == 1 && i != 1)
            buffer += to_string((i / (width + 2)) - 1);
        else if (i == (9 * (width + 2) + (width + 2) + logic::getPlayerX() + 2))
            buffer += "^";
        else if (Enemy::getEnemyByBufferPos(i)->getHealth() == 2 && Enemy::getEnemyByBufferPos(i) == logic::getNearestEnemy())
            buffer += "\033[1;36m";
        else if(Enemy::getEnemyByBufferPos(i)->getHealth() == 2 && Enemy::getEnemyByBufferPos(i) != logic::getNearestEnemy())
            buffer += "\033[1;34m";
        else if (Enemy::getEnemyByBufferPos(i)->getHealth() == 1 && Enemy::getEnemyByBufferPos(i) == logic::getNearestEnemy())
            buffer += "\033[1;33m";
        else if (Enemy::getEnemyByBufferPos(i)->getHealth() == 1 && Enemy::getEnemyByBufferPos(i) != logic::getNearestEnemy())
            buffer += "\033[1;31m";
        else
            buffer += '.';

        if (Enemy::getEnemyByBufferPos(i)->getType() == 1 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
            buffer += "o";
        else if (Enemy::getEnemyByBufferPos(i)->getType() == 2 && Enemy::getEnemyByBufferPos(i)->getHealth() != 0)
            buffer += "*";

        buffer += ' ';  
    }
    buffer += '\0';

    system("cls");
    cout << buffer;
    end_print_time = clock();
}

clock_t graphics::getPrint_time()
{
    return print_time;
}

clock_t graphics::getEnd_print_time()
{
    return end_print_time;
}