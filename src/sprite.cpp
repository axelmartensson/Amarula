#include <iostream>
#include <fstream>
#include <cstdlib>
#include "game.h"
using namespace std;

Sprite::Sprite(Display* tmpd, const char letter, int tmpdimX, int tmpdimY, int tmpposX, int tmpposY)
{
    d=tmpd;
    dimX = tmpdimX; dimY = tmpdimY;
    posX = tmpposX; posY = tmpposY;
    charactor = letter;
}

void Sprite::move(int nx, int ny)
{
    posX += nx;
    posY += ny;
}

void Sprite::clear()
{
    int i,j;
    for(i=0;i<dimY;i++)
    {

        for(j=0;j<dimX;j++)
        {
            d->set(i+posY, j+posX, EMPTY);
        }
    }
}

void Sprite::draw()
{
    int i,j;
    for(i=0;i<dimY;i++)
    {

        for(j=0;j<dimX;j++)
        {
            d->set(i+posY, j+posX, charactor);
        }
    }

}

bool Sprite::collideRect(Sprite &spr)
{
    if (bottom() < spr.top())
        return false;
    if (top() > spr.bottom())
        return false;
    if (right() < spr.left())
        return false;
    if (left() > spr.right())
        return false;

    return true;
}

int Sprite::top(){return posY;}
int Sprite::bottom(){return posY+dimY;}
int Sprite::left(){return posX;}
int Sprite::right(){return posX+dimX;}
