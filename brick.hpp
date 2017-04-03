#include"rect.hpp"
#include"consts.h"

class Brick:public Rect{
public:
  Brick(int row, int col){
    x = BRICK_GAP+col*(BRICK_WIDTH+BRICK_GAP)-1;
    y =  2*BRICK_GAP+row*(BRICK_HEIGHT+BRICK_GAP);
    vx=0;
    vy=0;
    height = BRICK_HEIGHT;
    width = BRICK_WIDTH;
    color = colors[row];
    solid=true;
  }

  void onCollision(){
    solid=false;
  }

};
