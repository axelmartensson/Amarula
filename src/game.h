
#include <vector>
using namespace std;
const char EMPTY = ' ';
const int SCREEN_WIDTH = 200;
const int SCREEN_HEIGHT = 30;

void wait(float seconds);

class Display;

class Sprite
{
      protected:
      Display* d;
      int dimX,dimY,posX,posY;
      char charactor;
      void update_rect();
      public:
             Sprite(Display* tmpd, const char letter, int dimX, int dimY, int posX, int posY);
             void move(int nx, int ny);
             void clear();
             void draw();
             bool collideRect(Sprite &spr);
             int top();
             int bottom();
             int left();
             int right();
};

class SpriteGroup
{
    int nOfSprites;
    vector<Sprite*> spriteDict;
    public:
           SpriteGroup();
           void add(Sprite* s);
           void clear();
           void draw();

};

class Display
{
      char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
      public:
             Display();
             bool set(int y, int x, char c);
             void update();


};

