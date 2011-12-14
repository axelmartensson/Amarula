
#include <iostream>
#include "game.h"
#include "keyboard.h"
using namespace std;

class Rack : public Sprite
{
    public:
        Rack(Display* tmpd, const char letter, int dimX, int dimY, int posX, int posY):Sprite(tmpd, letter, dimX, dimY, posX, posY){}
        void ai(Sprite spr)
        {
            if (spr.bottom() > top())
            {
                move(0,-1);
            }
            else if (spr.top() < bottom())
            {
                move(0,1);
            }
        }
};

int main()
{
    int player1Score=0,player2Score=0;
    int dx=2,dy=1;
    Display screen;
    Sprite boll(&screen, 'B',2,2, (SCREEN_WIDTH/2),(SCREEN_HEIGHT/2));
    Rack player1(&screen, 'H',1,8, 2,2);
    Rack player2(&screen, 'H',1,8, (SCREEN_WIDTH-3),2);

    SpriteGroup allSprites;
    allSprites.add(&boll);
    allSprites.add(&player1);
    allSprites.add(&player2);
    bool kG=true;

    while(kG)
    {
        allSprites.clear();

        if (boll.right() >= SCREEN_WIDTH) {dx =- dx;player1Score+=1;}
        if (boll.left() <= 0) {dx =- dx;player2Score+=1;}
        if (boll.bottom() >= SCREEN_HEIGHT || boll.top() <= 0) dy =- dy;
        if (boll.collideRect(player1) || boll.collideRect(player2)) dx=-dx;

        boll.move(dx,dy);
        allSprites.draw();

        screen.update();
        wait(0.2);

    }

    cout << "\tPLAYER 1 Score: " << player1Score << "\tPLAYER 2 Score" << player2Score;
    return 0;
}
