#include<vector>

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

#pragma once
#include"consts.h"

typedef std::vector<Brick> Bricks;

bool detectCollision(Ball &ball, Rect &rect);

class GameObjects{
private:
  Paddle paddle;
  Bricks bricks;
public:
  Ball ball;
  bool left_pressed;
  bool right_pressed;

  GameObjects(){
    left_pressed=false;
    right_pressed=false;
    ball.reset(paddle);

    for(int row=0;row<7;row++)
      for(int col=0; col<8; col++)
        bricks.push_back(Brick(row,col));
  }
  void movePaddleOnKey(){

    if(!left_pressed && right_pressed && paddle.x+PADDLE_WIDTH<1)
      paddle.vx=0.05;
    if(!right_pressed && left_pressed && paddle.x>-1)
      paddle.vx=-0.05;

    if(!left_pressed && !right_pressed)
      paddle.vx=0.0;


    if(!ball.moving)
      ball.reset(paddle);

  }

/*
  void movePaddleOnMouse(float x){
    paddle.x = x;
  }
*/

  void draw(){
    //move paddle
    movePaddleOnKey();
    //detect collision with boundary
    if(ball.x-BALL_RADIUS<-1)
      ball.vx = -ball.vx;
    if(ball.x+BALL_RADIUS>1)
      ball.vx = -ball.vx;
    if(ball.y-BALL_RADIUS<-1)
      ball.reset(paddle);
    if(ball.y+BALL_RADIUS>1)
      ball.vy = -ball.vy;

    //collision with rect
    detectCollision(ball,paddle);
    for(Bricks::iterator i = bricks.begin(); i!=bricks.end(); i++)
      detectCollision(ball, *i);

/*
    //if ball is within paddle's width
    if(ball.x>paddle.x && ball.x<paddle.x+PADDLE_WIDTH){
      float ball_paddle_dist = ball.y-BALL_RADIUS-paddle.y-PADDLE_HEIGHT/2;
      if(ball_paddle_dist<0)
      if(ball_paddle_dist <=0 && fabs(ball_paddle_dist)<PADDLE_HEIGHT){
        ball.vy = BALL_VY;
        ball.vx += paddle.vx/5;
      }
    }
*/

    ball.draw();
    paddle.draw();
    for(Bricks::iterator i = bricks.begin(); i!=bricks.end(); i++)
      i->draw();

  }

};

bool detectCollision(Ball &ball, Rect &rect){
  bool collided=false;
  if(!rect.solid)
    return false;
  if(ball.x>rect.x && ball.x<rect.x+rect.width){

    float ball_rect_dist = ball.y-ball.radius-rect.y;
    if(ball_rect_dist <=0 && fabs(ball_rect_dist)<rect.height){
      ball.vy = -ball.vy;
      puts("up");
      collided=true;
    }

    ball_rect_dist = ball.y+ball.radius-rect.y+rect.height;
    if(ball_rect_dist >=0 && fabs(ball_rect_dist)<rect.height){
      ball.vy = -ball.vy;
      puts("down");
      collided = true;
    }
  }
/*
  if(ball.y <= rect.y && ball.y>=rect.y-rect.height){
    if(ball.x+ball.radius>=rect.x){
      ball.vx = -ball.vx;
      collided=true;
    }
    if(ball.x-ball.radius<=rect.x+rect.width){
      ball.vx = -ball.vx;
      collided=true;
    }
  }

  if(ball.x >= rect.x && ball.x<=rect.x+rect.width){
    if(ball.y-ball.radius-rect.y<=rect.height){
      printf("y\n");
      ball.vy = -ball.vy;
      collided=true;
    }
    if(ball.y+ball.radius-rect.y-rect.height>=rect.height){
      printf("-y\n");
      ball.vy = -ball.vy;
      collided=true;
    }
  }
*/
  if(collided)
    rect.onCollision();
  return collided;

}
