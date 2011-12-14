#include <cstdlib>
#include <iostream>
#include "game.h"
using namespace std;

int main(int argc, char *argv[])
{
    Display skarm;
    SpriteGroup racketar;
    Sprite racket(skarm, 'A',3,13, 4,5);
    racketar.add(&racket);
    skarm.update();
    racketar.clear(skarm);
    racket.move(skarm, -3,-3);
    racketar.draw(skarm);
    skarm.update();
    return EXIT_SUCCESS;
}
