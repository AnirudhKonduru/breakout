#pragma once

#include"rect.hpp"

class Paddle:public Rect{
public:
  Paddle(){
    x=PADDLE_X-PADDLE_WIDTH/2;
    y=PADDLE_Y-PADDLE_HEIGHT/2;
    height = PADDLE_HEIGHT;
    width = PADDLE_WIDTH;
    vx=0.0;
    vy=0;
    color = hex2glcolor(0x212121);
    solid=true;
  }

  //void onCollision(){};

};
