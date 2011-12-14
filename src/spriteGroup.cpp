#include "game.h"
SpriteGroup::SpriteGroup()
{nOfSprites=0;}
void SpriteGroup::add(Sprite* s)
{
    spriteDict.push_back(s);
    nOfSprites +=1;
}

void SpriteGroup::clear()
{
    int elements = nOfSprites;
    for(int i=0; i<elements; i++)
    spriteDict[i]->clear();
}

void SpriteGroup::draw()
{
    int elements = nOfSprites;
    for(int i=0; i<elements; i++)
    spriteDict[i]->draw();
}
