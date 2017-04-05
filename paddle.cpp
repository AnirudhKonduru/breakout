#include"paddle.hpp"

Paddle::Paddle()
{
  x=PADDLE_X-PADDLE_WIDTH/2;
  y=PADDLE_Y-PADDLE_HEIGHT/2;
  height = PADDLE_HEIGHT;
  width = PADDLE_WIDTH;
  vx=0.0;
  vy=0;
  color = {0,0,0};
  solid=true;
}
