#include <cstdlib>
#include <iostream>
#include <ctime>
#include "game.h"
using namespace std;

Display::Display()
{

            int i,j;
            for(i=0;i<SCREEN_HEIGHT;i++)
            {
                for(j=0;j<SCREEN_WIDTH;j++)
                {
                    screen[i][j] = EMPTY;
                }
            }

}



void Display::update()
{
    system("clear");
     int i,j;
     //foreach line in vector:
            for(i=0;i<SCREEN_HEIGHT;i++)
            {
                //foreach element in line:
                for(j=0;j<SCREEN_WIDTH;j++)
                {
                    cout << screen[i][j];
                }
                cout << '\n';
            }
}


bool Display::set(int y, int x, char c)
{
     if(x<SCREEN_WIDTH && y<SCREEN_HEIGHT)
     {
                       screen[y][x]=c;return(true);
     }
     else return(false);
}


